# CuteGUI
Awesome c++ framework for desktop applications. Inspired by Vue.js. Easy, scalable and fast

## CuteGUI Structure
> CmakeLists.txt

> AppName
  
>> index.cpp
  
  
>> dependecies
  
  
>> src

>>> assets

>>> components

>>> routes

>>> store

>>> screens

> bin

>> AppName-debug

>> Appname-release

### Also we have project manager named as cgm(CuteGUIManager)
#### cgm commands
> cgm run -> run build shared binary debug file and start application(--nostart to disable)

> cgm build static(shared) -> run build static or shared binary release file

> cgm startproject 'projectName' -> start new project with 'projectName'

> cgm install 'lib' -> install library from CuteGuiRepository(Repository of ready to use libraries)
