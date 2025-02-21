/*
* Copyright (c) 2020, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     decode_downsampling_packet.cpp
//! \details  The decode down sampling feature interface is further sub-divided by codec standard,
//!           this file is for the base interface which is shared by all codecs.
//!
#include "decode_downsampling_packet.h"
#include "decode_common_feature_defs.h"

#ifdef _DECODE_PROCESSING_SUPPORTED

namespace decode
{

DecodeDownSamplingPkt::DecodeDownSamplingPkt(DecodePipeline *pipeline, CodechalHwInterface *hwInterface)
    : DecodeSubPacket(pipeline, hwInterface)
{}

DecodeDownSamplingPkt::~DecodeDownSamplingPkt()
{
    MOS_Delete(m_sfcInterface);
}

MOS_STATUS DecodeDownSamplingPkt::Init()
{
    DECODE_CHK_NULL(m_pipeline);
    DECODE_CHK_NULL(m_hwInterface);

    m_miInterface = m_hwInterface->GetMiInterface();
    DECODE_CHK_NULL(m_miInterface);

    MediaFeatureManager *featureManager = m_pipeline->GetFeatureManager();
    DECODE_CHK_NULL(featureManager);

    m_basicFeature = dynamic_cast<DecodeBasicFeature *>(
        featureManager->GetFeature(FeatureIDs::basicFeature));
    DECODE_CHK_NULL(m_basicFeature);

    m_downSampling = dynamic_cast<DecodeDownSamplingFeature *>(
        featureManager->GetFeature(DecodeFeatureIDs::decodeDownSampling));
    DECODE_CHK_NULL(m_downSampling);

    m_sfcInterface = MOS_New(MediaSfcInterface, m_hwInterface->GetOsInterface());
    DECODE_CHK_NULL(m_sfcInterface);

    MOS_ZeroMemory(&m_SfcParams, sizeof(m_SfcParams));
    return MOS_STATUS_SUCCESS;
}

MOS_STATUS DecodeDownSamplingPkt::Prepare()
{
    DECODE_FUNC_CALL();
    return MOS_STATUS_SUCCESS;
}

MOS_STATUS DecodeDownSamplingPkt::Execute(MOS_COMMAND_BUFFER& cmdBuffer)
{
    DECODE_FUNC_CALL();

    if (!m_downSampling->IsEnabled())
    {
        m_isSupported = false;
        return MOS_STATUS_SUCCESS;
    }

    DECODE_CHK_STATUS(InitSfcParams(m_SfcParams));
    if (m_sfcInterface->IsParameterSupported(m_SfcParams) == MOS_STATUS_SUCCESS)
    {
        m_isSupported = true;
    }
    else
    {
        m_isSupported = false;
    }

    if (m_isSupported)
    {
        DECODE_CHK_STATUS(m_sfcInterface->Render(&cmdBuffer, m_SfcParams));
    }

    return MOS_STATUS_SUCCESS;
}

MOS_STATUS DecodeDownSamplingPkt::CalculateCommandSize(uint32_t &commandBufferSize, uint32_t &requestedPatchListSize)
{
    // The command buffer size of SFC related commands should be calculated by picture packet,
    // so just return zero here.
    commandBufferSize = 0;
    requestedPatchListSize = 0;
    return MOS_STATUS_SUCCESS;
}

MOS_STATUS DecodeDownSamplingPkt::InitSfcParams(VDBOX_SFC_PARAMS &sfcParams)
{
    DECODE_FUNC_CALL();

    DECODE_CHK_NULL(m_downSampling->m_inputSurface);

    sfcParams.input.width         = m_downSampling->m_inputSurface->dwWidth;
    sfcParams.input.height        = m_downSampling->m_inputSurface->dwHeight;
    sfcParams.input.format        = m_downSampling->m_inputSurface->Format;
    sfcParams.input.colorSpace    = CSpace_Any;
    sfcParams.input.chromaSiting  = m_downSampling->m_chromaSitingType;
    sfcParams.input.mirrorEnabled = (m_downSampling->m_mirrorState != 0);

    sfcParams.output.surface      = &(m_downSampling->m_outputSurface);
    sfcParams.output.colorSpace   = CSpace_Any;
    sfcParams.output.chromaSiting = m_downSampling->m_chromaSitingType;
    sfcParams.output.rcDst.left   = m_downSampling->m_outputSurfaceRegion.m_x;
    sfcParams.output.rcDst.top    = m_downSampling->m_outputSurfaceRegion.m_y;
    sfcParams.output.rcDst.right  = m_downSampling->m_outputSurfaceRegion.m_x +
                                    m_downSampling->m_outputSurfaceRegion.m_width;
    sfcParams.output.rcDst.bottom = m_downSampling->m_outputSurfaceRegion.m_y +
                                    m_downSampling->m_outputSurfaceRegion.m_height;

    sfcParams.videoParams.codecStandard = m_basicFeature->m_standard;

    // If histogram is enabled
    if (m_downSampling->m_histogramDestSurf || m_downSampling->m_histogramDebug)
    {
        sfcParams.output.histogramBuf = m_downSampling->m_histogramBuffer;
    }

    return MOS_STATUS_SUCCESS;
}

}

#endif  // !_DECODE_PROCESSING_SUPPORTED
