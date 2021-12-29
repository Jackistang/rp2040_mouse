

- 电子森林板卡资料：https://www.eetree.cn/project/detail/698
- RP2040 官方资料：https://www.raspberrypi.com/documentation/microcontrollers/rp2040.html
- C/C++ SDK：https://github.com/raspberrypi/pico-sdk



配置 VSCode 环境：getting-started-with-pico.pdf - 9.2.4

PICO-SDK Linux 环境搭建（Using Picoprobe）：

1. 参照 getting-started-with-pico.pdf - Chapter 2 安装 SDK 以及相应的工具链。
2. 参照文章 [Raspberry Pi Pico and RP2040 - C/C++ Part 2: Debugging with VS Code](https://www.digikey.bg/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-2-debugging-with-vs-code/470abc7efb07432b82c95f6f67f184c0) 搭建 OpenOCD (RP2040 版本) 环境和配置 VSCode 工程。

【注意事项】：Ubuntu 18.04 arm-none-eabi-gdb 没有加入 apt 源，需要手动从源码编译，参考：[解决ubuntu18安装arm-none-eabi-gdb问题](https://zhuanlan.zhihu.com/p/134031693)。

----

参考项目：

- LVGL_SUB_Mouse：https://github.com/k-ying/LVGL_USB_Mouse
- 



![UART0 引脚图](https://gitee.com/jackis/blog-images/raw/master/images/image-20211225215958828.png)



![HID Descriptor](https://gitee.com/jackis/blog-images/raw/master/images/image-20211225230833406.png)



Main item type: 

- Input item tag
- Output
- Feature
- Collection
- End Collection

Local item 描述下一个 Main item。

Global item 成为描述符中后续数据属性的默认值。



![](https://gitee.com/jackis/blog-images/raw/master/images/image-20211226192824840.png)



![](https://gitee.com/jackis/blog-images/raw/master/images/image-20211227204248776.png)

- HID 整体流程理解：https://zhuanlan.zhihu.com/p/27568561
- HID Usage 理解：https://blog.csdn.net/hzt12345hf/article/details/51995042
- HID Collection 理解：

