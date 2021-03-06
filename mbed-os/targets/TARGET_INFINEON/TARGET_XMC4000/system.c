#include <xmc_scu.h>

/* Clock configuration */
XMC_SCU_CLOCK_CONFIG_t clock_config =
{
  .syspll_config.p_div = 2,
  .syspll_config.n_div = 80,
  .syspll_config.k_div = 4,
  .syspll_config.mode = XMC_SCU_CLOCK_SYSPLL_MODE_NORMAL,
  .syspll_config.clksrc = XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP,
  .enable_oschp = true,
  .calibration_mode = XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_FACTORY,
  .fsys_clksrc = XMC_SCU_CLOCK_SYSCLKSRC_PLL,
  .fsys_clkdiv = 1,
  .fcpu_clkdiv = 1,
  .fccu_clkdiv = 1,
  .fperipheral_clkdiv = 1
};

void SystemCoreClockSetup(void)
{
  /* Setup settings for USB clock */
  XMC_SCU_CLOCK_Init(&clock_config);

  XMC_SCU_HIB_SetRtcClockSource(XMC_SCU_HIB_RTCCLKSRC_ULP);

  XMC_SCU_CLOCK_EnableUsbPll();
  XMC_SCU_CLOCK_StartUsbPll(2, 64);
  XMC_SCU_CLOCK_SetUsbClockDivider(4);
  XMC_SCU_CLOCK_SetUsbClockSource(XMC_SCU_CLOCK_USBCLKSRC_USBPLL);
  XMC_SCU_CLOCK_EnableClock(XMC_SCU_CLOCK_USB);

  SystemCoreClockUpdate();
}
