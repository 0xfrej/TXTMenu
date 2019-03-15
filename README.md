# TXTMenu
Library for creating menu for alphanumeric displays. It's written with usage on MCU and easy modification in mind. Code is highly customizable and the only dependance is libstdc which should be supported on most devices. Target platform is AVR, but can be easily ported to other platforms, since it's based only on standard C libraries and other parts are through driver wrappers.
I know that I'm not very good programmer and i could save much more program memory, but right now i don't have much time to improve it that much and since mostly controller I use with this library is ATmega32 and ATmega168, I don't have this kind of problem. But if you have an idea feel free to contribute. In near future of 2019 I will add documentation and examples.

## Main features
* multilangual
* cross-platform
* easy modification with user defined classes
* variable displaying and editing
* executing an function by selecting item
* 

### By modification I mean...
Library contains basic classes

### To be done
* Dynamic memory garbage collecting (library was designed to be loaded on mcu start and used whole time right now)
* Single language setting (for memory savings)
* code cleaning
* variable editing overflow prevention (min, max value limit)

## Authors

* **Peter Karaba** <brostrix@gmail.com> - [brostrix](https://github.com/brostrix)

See also the list of [contributors](https://github.com/brostrix/ictus/contributors) who participated in this project.

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](LICENSE.md) file for details

## Dependencies
* libstdc

### Used software in this repository (not needed for build)
* HD44780 driver 2.0 by Peter Fleury
