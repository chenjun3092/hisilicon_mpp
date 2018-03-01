/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : isp_gamma.c
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/01/16
  Description   : 
  History       :
  1.Date        : 2013/01/16
    Author      : n00168968
    Modification: Created file

******************************************************************************/
#include "isp_ext_config.h"
#include "isp_gamma_rgb_mem_config.h"
#include "isp_alg.h"
#include "isp_sensor.h"
#include "isp_config.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

HI_VOID GammaInitLin(ISP_DEV IspDev)
{
    HI_S32 i;
    #if 0
    HI_U16  au16sRGB[GAMMA_NODE_NUMBER]={
           0,  203,  347,  452,  539,  613,  679,  739,  794,  846,  894,  939,  982, 1023,
        1062, 1100, 1136, 1171, 1204, 1237, 1268, 1299, 1329, 1358, 1386, 1414, 1441, 1467,
        1493, 1519, 1543, 1568, 1592, 1615, 1638, 1661, 1683, 1705, 1726, 1748, 1769, 1789,
        1810, 1830, 1849, 1869, 1888, 1907, 1926, 1945, 1963, 1981, 1999, 2017, 2034, 2052,
        2069, 2086, 2102, 2119, 2136, 2152, 2168, 2184, 2200, 2216, 2231, 2247, 2262, 2277,
        2292, 2307, 2322, 2337, 2351, 2366, 2380, 2394, 2408, 2422, 2436, 2450, 2464, 2477,
        2491, 2504, 2518, 2531, 2544, 2557, 2570, 2583, 2596, 2609, 2621, 2634, 2646, 2659,
        2671, 2683, 2696, 2708, 2720, 2732, 2744, 2756, 2767, 2779, 2791, 2802, 2814, 2825,
        2837, 2848, 2859, 2871, 2882, 2893, 2904, 2915, 2926, 2937, 2948, 2959, 2969, 2980,
        2991, 3001, 3012, 3023, 3033, 3043, 3054, 3064, 3074, 3085, 3095, 3105, 3115, 3125,
        3135, 3145, 3155, 3165, 3175, 3185, 3194, 3204, 3214, 3224, 3233, 3243, 3252, 3262,
        3271, 3281, 3290, 3300, 3309, 3318, 3327, 3337, 3346, 3355, 3364, 3373, 3382, 3391,
        3400, 3409, 3418, 3427, 3436, 3445, 3454, 3463, 3471, 3480, 3489, 3498, 3506, 3515,
        3523, 3532, 3540, 3549, 3557, 3566, 3574, 3583, 3591, 3600, 3608, 3616, 3624, 3633,
        3641, 3649, 3657, 3665, 3674, 3682, 3690, 3698, 3706, 3714, 3722, 3730, 3738, 3746,
        3754, 3762, 3769, 3777, 3785, 3793, 3801, 3808, 3816, 3824, 3832, 3839, 3847, 3855,
        3862, 3870, 3877, 3885, 3892, 3900, 3907, 3915, 3922, 3930, 3937, 3945, 3952, 3959,
        3967, 3974, 3981, 3989, 3996, 4003, 4010, 4018, 4025, 4032, 4039, 4046, 4054, 4061,
        4068, 4075, 4082, 4089, 4095
        };
    #endif

    /*the following gamma is not really sRGB gamma*/
    HI_U16  au16sRGB[GAMMA_NODE_NUMBER]={
        0   ,120 ,220 ,310 ,390 ,470 ,540 ,610 ,670 ,730 ,786 ,842 ,894 ,944 ,994 ,1050,    
        1096,1138,1178,1218,1254,1280,1314,1346,1378,1408,1438,1467,1493,1519,1543,1568,    
        1592,1615,1638,1661,1683,1705,1726,1748,1769,1789,1810,1830,1849,1869,1888,1907,    
        1926,1945,1963,1981,1999,2017,2034,2052,2069,2086,2102,2119,2136,2152,2168,2184,    
        2200,2216,2231,2247,2262,2277,2292,2307,2322,2337,2351,2366,2380,2394,2408,2422,    
        2436,2450,2464,2477,2491,2504,2518,2531,2544,2557,2570,2583,2596,2609,2621,2634,    
        2646,2659,2671,2683,2696,2708,2720,2732,2744,2756,2767,2779,2791,2802,2814,2825,    
        2837,2848,2859,2871,2882,2893,2904,2915,2926,2937,2948,2959,2969,2980,2991,3001,    
        3012,3023,3033,3043,3054,3064,3074,3085,3095,3105,3115,3125,3135,3145,3155,3165,    
        3175,3185,3194,3204,3214,3224,3233,3243,3252,3262,3271,3281,3290,3300,3309,3318,    
        3327,3337,3346,3355,3364,3373,3382,3391,3400,3409,3418,3427,3436,3445,3454,3463,    
        3471,3480,3489,3498,3506,3515,3523,3532,3540,3549,3557,3566,3574,3583,3591,3600,    
        3608,3616,3624,3633,3641,3649,3657,3665,3674,3682,3690,3698,3706,3714,3722,3730,    
        3738,3746,3754,3762,3769,3777,3785,3793,3801,3808,3816,3824,3832,3839,3847,3855,    
        3862,3870,3877,3885,3892,3900,3907,3915,3922,3930,3937,3945,3952,3959,3967,3974,    
        3981,3989,3996,4003,4010,4018,4025,4032,4039,4046,4054,4061,4068,4075,4082,4089,4095
        };
	//modify by qlp
    hi_isp_gamma_waddr_write(IspDev, 0);
    for (i=0; i<GAMMA_NODE_NUMBER; i++)
    {
        hi_isp_gamma_wdata_write(IspDev, (HI_U32)(au16sRGB[i]));
    }
	hi_isp_gamma_lut_update_write(IspDev, 1);

    return;
}

HI_VOID GammaInitWDR(ISP_DEV IspDev)
{
    HI_S32 i;
#if 1   /* sRGB gamma in WDR mode */
    HI_U16 au16sqrt2sRGB[GAMMA_NODE_NUMBER]={
            0,    16,    32,    48,    64,    80,    96,   112,   128,   144,   160,   176,   192,   208,   224,   240,
   256,   272,   288,   304,   320,   336,   352,   368,   384,   400,   416,   432,   448,   464,   480,   496,
   512,   528,   544,   560,   576,   592,   608,   624,   640,   656,   672,   688,   704,   720,   736,   752,
   768,   784,   800,   816,   832,   848,   864,   880,   896,   912,   928,   944,   960,   976,   992,  1008,
  1024,  1040,  1056,  1072,  1088,  1104,  1120,  1136,  1152,  1168,  1184,  1200,  1216,  1232,  1248,  1264,
  1280,  1296,  1312,  1328,  1344,  1360,  1376,  1392,  1408,  1424,  1440,  1456,  1472,  1488,  1504,  1520,
  1536,  1552,  1568,  1584,  1600,  1616,  1632,  1648,  1664,  1680,  1696,  1712,  1728,  1744,  1760,  1776,
  1792,  1808,  1824,  1840,  1856,  1872,  1888,  1904,  1920,  1936,  1952,  1968,  1984,  2000,  2016,  2032,
  2048,  2064,  2080,  2096,  2112,  2128,  2144,  2160,  2176,  2192,  2208,  2224,  2240,  2256,  2272,  2288,
  2304,  2320,  2336,  2352,  2368,  2384,  2400,  2416,  2432,  2448,  2464,  2480,  2496,  2512,  2528,  2544,
  2560,  2576,  2592,  2608,  2624,  2640,  2656,  2672,  2688,  2704,  2720,  2736,  2752,  2768,  2784,  2800,
  2816,  2832,  2848,  2864,  2880,  2896,  2912,  2928,  2944,  2960,  2976,  2992,  3008,  3024,  3040,  3056,
  3072,  3088,  3104,  3120,  3136,  3152,  3168,  3184,  3200,  3216,  3232,  3248,  3264,  3280,  3296,  3312,
  3328,  3344,  3360,  3376,  3392,  3408,  3424,  3440,  3456,  3472,  3488,  3504,  3520,  3536,  3552,  3568,
  3584,  3600,  3616,  3632,  3648,  3664,  3680,  3696,  3712,  3728,  3744,  3760,  3776,  3792,  3808,  3824,
  3840,  3856,  3872,  3888,  3904,  3920,  3936,  3952,  3968,  3984,  4000,  4016,  4032,  4048,  4064,  4080,
  4095

        };
#endif
#if 0   /* default gamma in WDR mode */
    HI_U16 au16sqrt2sRGB[GAMMA_NODE_NUMBER]={
           0,   1,   2,   4,   8,  12,  17,  23,  30,  38,  47,  57,  68,  79,  92, 105,
         120, 133, 147, 161, 176, 192, 209, 226, 243, 260, 278, 296, 315, 333, 351, 370,
         390, 410, 431, 453, 474, 494, 515, 536, 558, 580, 602, 623, 644, 665, 686, 708,
         730, 751, 773, 795, 818, 840, 862, 884, 907, 929, 951, 974, 998,1024,1051,1073,
        1096,1117,1139,1159,1181,1202,1223,1243,1261,1275,1293,1313,1332,1351,1371,1389,
        1408,1427,1446,1464,1482,1499,1516,1533,1549,1567,1583,1600,1616,1633,1650,1667,
        1683,1700,1716,1732,1749,1766,1782,1798,1815,1831,1847,1863,1880,1896,1912,1928,
        1945,1961,1977,1993,2009,2025,2041,2057,2073,2089,2104,2121,2137,2153,2168,2184,
        2200,2216,2231,2248,2263,2278,2294,2310,2326,2341,2357,2373,2388,2403,2419,2434,
        2450,2466,2481,2496,2512,2527,2543,2558,2573,2589,2604,2619,2635,2650,2665,2680,
        2696,2711,2726,2741,2757,2771,2787,2801,2817,2832,2847,2862,2877,2892,2907,2922,
        2937,2952,2967,2982,2997,3012,3027,3041,3057,3071,3086,3101,3116,3130,3145,3160,
        3175,3190,3204,3219,3234,3248,3263,3278,3293,3307,3322,3337,3351,3365,3380,3394,
        3409,3424,3438,3453,3468,3482,3497,3511,3525,3540,3554,3569,3584,3598,3612,3626,
        3641,3655,3670,3684,3699,3713,3727,3742,3756,3770,3784,3799,3813,3827,3841,3856,
        3870,3884,3898,3912,3927,3941,3955,3969,3983,3997,4011,4026,4039,4054,4068,4082,4095
        };
#endif
#if 0   /* high contrast gamma in WDR mode */
    HI_U16 au16sqrt2sRGB[GAMMA_NODE_NUMBER]={
        0,1,1,2,3,5,8,10,14,17,21,26,30,36,41,47,54,61,68,75,83,92,100,109,119,129,139,150,161,173,184,196,209,222,235,248,262,276,290,305,320,335,351,366,382,399,415,433,450,467,484,502,520,539,557,576,595,614,634,653,673,693,714,734,754,775,796,816,837,858,879,901,923,944,966,988,1010,1032,1054,1076,1098,1120,1142,1165,1188,1210,1232,1255,1278,1301,1324,1346,1369,1391,1414,1437,1460,1483,1505,1528,1551,1574,1597,1619,1642,1665,1687,1710,1732,1755,1777,1799,1822,1845,1867,1889,1911,1933,1955,1977,1999,2021,2043,2064,2086,2108,2129,2150,2172,2193,2214,2236,2256,2277,2298,2319,2340,2360,2380,2401,2421,2441,2461,2481,2501,2521,2541,2560,2580,2599,2618,2637,2656,2675,2694,2713,2732,2750,2769,2787,2805,2823,2841,2859,2877,2895,2912,2929,2947,2964,2982,2999,3015,3032,3049,3066,3082,3099,3115,3131,3147,3164,3179,3195,3211,3227,3242,3258,3273,3288,3303,3318,3333,3348,3362,3377,3392,3406,3420,3434,3448,3462,3477,3490,3504,3517,3531,3544,3558,3571,3584,3597,3611,3623,3636,3649,3662,3674,3686,3698,3711,3723,3736,3748,3759,3771,3783,3795,3806,3818,3829,3841,3852,3863,3874,3885,3896,3907,3918,3929,3939,3949,3961,3971,3981,3991,4001,4012,4022,4032,4042,4051,4061,4071,4081,4090,4095
        };
#endif
	//modify by qlp
	hi_isp_gamma_waddr_write(IspDev, 0);
    for (i=0; i<GAMMA_NODE_NUMBER; i++)
    {
		hi_isp_gamma_wdata_write(IspDev, (HI_U32)(au16sqrt2sRGB[i]));
    }
	hi_isp_gamma_lut_update_write(IspDev, 1);
    return;
}

static HI_VOID GammaExtRegsDefault(HI_VOID)
{
	hi_ext_system_gamma_curve_type_write(HI_EXT_SYSTEM_GAMMA_CURVE_TYPE_DEFAULT);
    return;
}

static HI_VOID GammaRegsDefault(ISP_DEV IspDev) 
{
	hi_isp_gamma_enable_write(IspDev, HI_TRUE);
    return;
}

static HI_VOID GammaExtRegsInitialize(ISP_DEV IspDev)
{
    return;
}

static HI_VOID GammaRegsInitialize(ISP_DEV IspDev)
{
    HI_S32 i;
	ISP_CTX_S *pstIspCtx = HI_NULL;    
  
    ISP_CMOS_DEFAULT_S *pstSnsDft = HI_NULL;
	HI_U8 u8WDRMode;
   
    ISP_SensorGetDefault(IspDev, &pstSnsDft);
	ISP_GET_CTX(IspDev, pstIspCtx);

    u8WDRMode = pstIspCtx->u8SnsWDRMode;
    
    /* Enable gamma */
    hi_isp_gamma_enable_write(IspDev, 1);

    if (pstSnsDft->stGamma.bValid)
    {
		// modify by qlp
        hi_isp_gamma_waddr_write(IspDev, 0);
        for (i=0; i<GAMMA_NODE_NUMBER; i++)
        {
            hi_isp_gamma_wdata_write(IspDev, (HI_U32)pstSnsDft->stGamma.au16Gamma[i]); //12 bits, modify by q00214668
            //hi_isp_gamma_wdata_write((HI_U32)(pstSnsDft->stGamma.au16Gamma[i] >> 2));//10 bits, modify by q00214668
        }
		hi_isp_gamma_lut_update_write(IspDev, 1);
    }
    else
	{
	 	if (IS_LINEAR_MODE(u8WDRMode))
        {
            /* sensor in linear mode */
            GammaInitLin(IspDev);
        }
        else if (IS_WDR_MODE(u8WDRMode))
        {
            /* sensor in WDR mode */
            GammaInitWDR(IspDev);                
        }
        else
        {
            /* unknow u8Mode */
        }
     }
    
    return;
}

static HI_S32 GammaReadExtregs(ISP_DEV IspDev)
{
    return 0;
}

HI_S32 ISP_GammaInit(ISP_DEV IspDev)
{
    GammaRegsDefault(IspDev);
    GammaExtRegsDefault();
    GammaRegsInitialize(IspDev);
    GammaExtRegsInitialize(IspDev);
    
    return HI_SUCCESS;
}

HI_S32 ISP_GammaRun(ISP_DEV IspDev, const HI_VOID *pStatInfo,
    HI_VOID *pRegCfg, HI_S32 s32Rsv)
{
    GammaReadExtregs(IspDev);
    
    return HI_SUCCESS;
}

HI_S32 ISP_GammaCtrl(ISP_DEV IspDev, HI_U32 u32Cmd, HI_VOID *pValue)
{
    HI_S32 i;
    ISP_CMOS_DEFAULT_S *pstSnsDft = HI_NULL;
    HI_U8 u8Mode = *((HI_U8 *)pValue);
    
    ISP_SensorGetDefault(IspDev, &pstSnsDft);
    
    switch (u32Cmd)
    {
        case ISP_WDR_MODE_SET :
            if (pstSnsDft->stGamma.bValid)
            {
				//modify by qlp
                hi_isp_gamma_waddr_write(IspDev, 0);
                for (i=0; i<GAMMA_NODE_NUMBER; i++)
                {
                    hi_isp_gamma_wdata_write(IspDev, (HI_U32)pstSnsDft->stGamma.au16Gamma[i]);
                }
				hi_isp_gamma_lut_update_write(IspDev, 1);
            }
            else
            {
                if (IS_LINEAR_MODE(u8Mode))
                {
                    /* sensor in linear mode */
                    GammaInitLin(IspDev);
                }
                else if (IS_WDR_MODE(u8Mode))
                {
                    /* sensor in WDR mode */
                    GammaInitWDR(IspDev);                
                }
                else
                {
                    /* unknow u8Mode */
                }            
            }
            break;
        default :
            break;
    }
    return HI_SUCCESS;
}

HI_S32 ISP_GammaExit(ISP_DEV IspDev)
{
	hi_isp_gamma_enable_write(IspDev, HI_FALSE);
    return HI_SUCCESS;
}

HI_S32 ISP_AlgRegisterGamma(ISP_DEV IspDev)
{
    ISP_CTX_S *pstIspCtx = HI_NULL;
    ISP_ALG_NODE_S *pstAlgs = HI_NULL;
    
    ISP_GET_CTX(IspDev, pstIspCtx);

    pstAlgs = ISP_SearchAlg(pstIspCtx->astAlgs);
    ISP_CHECK_POINTER(pstAlgs);

    pstAlgs->enAlgType = ISP_ALG_GAMMA;
    pstAlgs->stAlgFunc.pfn_alg_init = ISP_GammaInit;
    pstAlgs->stAlgFunc.pfn_alg_run  = ISP_GammaRun;
    pstAlgs->stAlgFunc.pfn_alg_ctrl = ISP_GammaCtrl;
    pstAlgs->stAlgFunc.pfn_alg_exit = ISP_GammaExit;
    pstAlgs->bUsed = HI_TRUE;

    return HI_SUCCESS;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

