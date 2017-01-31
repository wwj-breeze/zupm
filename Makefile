# UPM top-level Makefile
ifdef CONFIG_UPM
ZEPHYRINCLUDE += -I$(srctree)/ext/lib/upm/include
endif
include $(srctree)/ext/lib/upm/src/a110x/Makefile
include $(srctree)/ext/lib/upm/src/ad8232/Makefile
include $(srctree)/ext/lib/upm/src/apa102/Makefile
include $(srctree)/ext/lib/upm/src/bh1750/Makefile
include $(srctree)/ext/lib/upm/src/collision/Makefile
include $(srctree)/ext/lib/upm/src/dfrorp/Makefile
include $(srctree)/ext/lib/upm/src/dfrph/Makefile
include $(srctree)/ext/lib/upm/src/emg/Makefile
include $(srctree)/ext/lib/upm/src/flex/Makefile
include $(srctree)/ext/lib/upm/src/gas/Makefile
include $(srctree)/ext/lib/upm/src/gp2y0a/Makefile
include $(srctree)/ext/lib/upm/src/gsr/Makefile
include $(srctree)/ext/lib/upm/src/hka5/Makefile
include $(srctree)/ext/lib/upm/src/joystick12/Makefile
include $(srctree)/ext/lib/upm/src/ldt0028/Makefile
include $(srctree)/ext/lib/upm/src/led/Makefile
include $(srctree)/ext/lib/upm/src/light/Makefile
include $(srctree)/ext/lib/upm/src/loudness/Makefile
include $(srctree)/ext/lib/upm/src/m24lr64e/Makefile
include $(srctree)/ext/lib/upm/src/mic/Makefile
include $(srctree)/ext/lib/upm/src/mma7361/Makefile
include $(srctree)/ext/lib/upm/src/moisture/Makefile
include $(srctree)/ext/lib/upm/src/mpr121/Makefile
include $(srctree)/ext/lib/upm/src/mq303a/Makefile
include $(srctree)/ext/lib/upm/src/nmea_gps/Makefile
include $(srctree)/ext/lib/upm/src/o2/Makefile
include $(srctree)/ext/lib/upm/src/relay/Makefile
include $(srctree)/ext/lib/upm/src/rotary/Makefile
include $(srctree)/ext/lib/upm/src/servo/Makefile
include $(srctree)/ext/lib/upm/src/sht1x/Makefile
include $(srctree)/ext/lib/upm/src/slide/Makefile
include $(srctree)/ext/lib/upm/src/temperature/Makefile
include $(srctree)/ext/lib/upm/src/tsl2561/Makefile
include $(srctree)/ext/lib/upm/src/ttp223/Makefile
include $(srctree)/ext/lib/upm/src/urm37/Makefile
include $(srctree)/ext/lib/upm/src/utilities/Makefile
include $(srctree)/ext/lib/upm/src/vdiv/Makefile
include $(srctree)/ext/lib/upm/src/water/Makefile
include $(srctree)/ext/lib/upm/src/yg1006/Makefile
include $(srctree)/ext/lib/upm/src/biss0001/Makefile
include $(srctree)/ext/lib/upm/src/bmi160/Makefile
include $(srctree)/ext/lib/upm/src/lcm1602/Makefile
include $(srctree)/ext/lib/upm/src/jhd1313m1/Makefile
include $(srctree)/ext/lib/upm/src/lm35/Makefile
include $(srctree)/ext/lib/upm/src/rotaryencoder/Makefile
include $(srctree)/ext/lib/upm/src/rpr220/Makefile
include $(srctree)/ext/lib/upm/src/md/Makefile
include $(srctree)/ext/lib/upm/src/linefinder/Makefile
include $(srctree)/ext/lib/upm/src/uln200xa/Makefile
include $(srctree)/ext/lib/upm/src/mma7660/Makefile
include $(srctree)/ext/lib/upm/src/buzzer/Makefile
include $(srctree)/ext/lib/upm/src/ppd42ns/Makefile
include $(srctree)/ext/lib/upm/src/guvas12d/Makefile
include $(srctree)/ext/lib/upm/src/otp538u/Makefile
include $(srctree)/ext/lib/upm/src/my9221/Makefile
include $(srctree)/ext/lib/upm/src/ms5803/Makefile
include $(srctree)/ext/lib/upm/src/ims/Makefile
include $(srctree)/ext/lib/upm/src/ecezo/Makefile
include $(srctree)/ext/lib/upm/src/button/Makefile
include $(srctree)/ext/lib/upm/src/mb704x/Makefile
include $(srctree)/ext/lib/upm/src/speaker/Makefile
include $(srctree)/ext/lib/upm/src/cjq4435/Makefile
include $(srctree)/ext/lib/upm/src/hmc5883l/Makefile
include $(srctree)/ext/lib/upm/src/enc03r/Makefile
include $(srctree)/ext/lib/upm/src/nunchuck/Makefile
