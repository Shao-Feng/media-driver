# Media Features Summary

## Supported Decoding Output Format and Max Resolution

(2k=2048x2048, 4k=4096x4096, 8k=8192x8192, 16k=16384x16384)

| Codec | Type | BDW | SKL | BXT/APL | KBLx | ICL | TGL/RKL | DG1/SG1 |
|---|---|---|---|---|---|---|---|---|
| AVC | Output | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. | 4k | 4k | 4k | 4k | 4k | 4k | 4k |
| MPEG-2 | Output | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. | 2k | 2k | 2k | 2k | 2k | 2k | 2k |
| VC-1 | Output | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. | 4k | 4k | 4k | 4k | 4k | 4k | 4k |
| JPEG* | Max Res. | 16k | 16k | 16k | 16k | 16k | 16k | 16k |
| VP8 | Output | NV12 | NV12 | NV12 | NV12 | NV12 | NV12** |  |
|  | Max Res. | 4k | 4k | 4k | 4k | 4k | 4k** |  |
| HEVC 8bit | Output |  | NV12 | NV12 | NV12 | NV12/YUY2/AYUV | NV12/YUY2/AYUV | NV12/YUY2/AYUV |
|  | Max Res. |  | 8k | 8k | 8k | 8k | 8k | 8k |
| HEVC 10bit | Output |  |  | P010 | P010 | P010/Y210/Y410 | P010/Y210/Y410 | P010/Y210/Y410 |
|  | Max Res. |  |  | 8k | 8k | 8k | 8k | 8k |
| HEVC 12bit | Output | | |  |  |  | P016/Y216/Y416 | P016/Y216/Y416 |
| | Max Res. | | |  |  |  | 8k | 8k |
| VP9 8bit | Output |  |  | NV12 | NV12 | NV12/AYUV | NV12/AYUV | NV12/AYUV |
|  | Max Res. |  |  | 4k | 8k | 8k | 8k | 8k |
| VP9 10bit | Output |  |  |  | P010 | P010/Y410 | P010/Y410 | P010/Y410 |
|  | Max Res. |  |  |  | 8k | 8k | 8k | 8k |
| VP9 12bit | Output | | | |  |  | P016/Y216/Y416 | P016/Y216/Y416 |
| | Max Res. | | | |  |  | 8k | 8k |
| AV1 8bit | Output | | | | | | NV12 | NV12 |
|  | Max Res. | | | | | | 8k | 8k |
| AV1 10bit | Output | | | | | | P010 | P010 |
|  | Max Res. | | | | | | 8k | 8k |

* \* JPEG output format: NV12/411P/422H/422V/444P/BGRP/RGBP/YUY2/ARGB
* \** VP8 is only supported on TGL platform

## Supported Encoding Input Format and Max Resolution

### Hardware Encoding, Low Power Encoding(VDEnc/Huc)

(4k=4096x4096, 16k=16384x16384)

| Codec | Type | BDW | SKL | BXT/APL | KBLx | ICL | TGL/RKL | DG1/SG1 |
|---|---|---|---|---|---|---|---|---|
| AVC | Input |  | NV12 | NV12 | More* | More* | More* | More* |
|  | Max Res. |  | 4k | 4k | 4k | 4k | 4k | 4k |
| JPEG | Input/Output |  | Note** | Note** | Note** | Note** | Note** | Note** |
|  | Max Res. |  | 16k | 16k | 16k | 16k | 16k | 16k |
| HEVC 8bit | Input |  |  |  |  | NV12/AYUV | NV12/AYUV | NV12/AYUV |
|  | Max Res. |  |  |  |  | 8K | 8K | 8K |
| HEVC 10bit | Input |  |  |  |  | P010/Y410 | P010/Y410 | P010/Y410 |
|  | Max Res. |  |  |  |  | 8k | 8k | 8k |
| VP9 8bit | Input |  |  |  |  | NV12/AYUV | NV12/AYUV | NV12/AYUV |
|  | Max Res. |  |  |  |  | 8k | 8k | 8k |
| VP9 10bit | Input |  |  |  |  | P010/Y410 | P010/Y410 | P010/Y410 |
|  | Max Res. |  |  |  |  | 8k | 8k | 8k |

* \* KBL/CFL/ICL/TGL AVC encoding supported input formats: NV12/YUY2/YUYV/YVYU/UYVY/AYUV/ARGB
* \** JPEG encoding supports input format NV12/YUY2/UYVY/AYUV/ABGR/Y8 and output format YUV400/YUV420/YUV422H_2Y/YUV444/RGB24.


### Hardware(PAK) + Shader(media kernel+VME) Encoding

(2k=2048x2048, 4k=4096x4096, 8k=8192x8192)

| Codec | Type | BDW | SKL | BXT/APL | KBLx | ICL | TGL/RKL | DG1/SG1 |
|---|---|---|---|---|---|---|---|---|
| AVC | Input | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. | 4k | 4k | 4k | 4k | 4k | 4k | 4k |
| MPEG2 | Input | NV12 | NV12 |  | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. | 2k | 2k |  | 2k | 2k | 2k | 2k |
| VP8 | Input |  |  |  | NV12 | NV12 | NV12 | NV12 |
|  | Max Res. |  |  |  | 4k | 4k | 4k | 4k |
| HEVC 8bit | Input |  | NV12 | NV12 | NV12 | NV12/AYUV | NV12/AYUV | NV12/AYUV |
|  | Max Res. |  | 4k | 4k | 4k | 8k | 8k | 8k |
| HEVC 10bit | Input |  |  |  |  | P010/Y410 | P010/Y410 | P010/Y410 |
|  | Max Res. |  |  |  |  | 8k | 8k | 8k |


## Supported Video Processing CSC/Scaling Format

|    Platform           | Format | NV12 | YV12 | I420 | P010 | YUY2 | UYVY | Y210 | AYUV | Y410 | P016*| Y216*| Y416*|
|-----------------------|--------|------|------|------|------|------|------|------|------|------|------|------|------|
|      BDW              | Input  |  Y   |  Y   |  Y   |      |  Y   |      |      |      |      |      |      |      |
|                       | Output |  Y   |  Y   |  Y   |      |  Y   |      |      |      |      |      |      |      |
|SKL/BXT/KBL/CFL/WHL/CML| Input  |  Y   |  Y   |  Y   |  Y   |  Y   |      |      |      |      |      |      |      |
|                       | Output |  Y   |  Y   |  Y   |      |  Y   |      |      |      |      |      |      |      |
|      ICL              | Input  |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |      |      |      |
|                       | Output |  Y   |  Y   |  Y   |  Y   |  Y   |      |  Y   |  Y   |  Y   |      |      |      |
|      JSL/EHL          | Input  |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |      |      |      |
|                       | Output |  Y   |  Y   |  Y   |  Y   |  Y   |      |  Y   |  Y   |  Y   |      |      |      |
|      TGL/RKL          | Input  |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |
|                       | Output |  Y   |  Y   |  Y   |  Y   |  Y   |      |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |
|      DG1/SG1          | Input  |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |
|                       | Output |  Y   |  Y   |  Y   |  Y   |  Y   |      |  Y   |  Y   |  Y   |  Y   |  Y   |  Y   |

* \* For SFC path, there are NOT real 16bit, SFC precision is 12bit; For kernel path, we support real 16bit.