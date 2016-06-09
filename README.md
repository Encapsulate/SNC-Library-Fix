# SNC-Library-Fix
Since SNC is broken, I've started making a library which quickly and smartly adds useful broken functions to the (SNC TOOLSET) SPRX.

# How to use SNC-Library-Fix library
For now, what you will have to do is open Visual Studio 201x and go Project->Properties->Configuration Properies->VC++ Directories and in "Include Directories" add the include folder from this repository.
Now navigate to Linker and in "Additional Dependencies" add SNCLib.a file path to the list.

That's it, now you're set to include for example
   #include <stdio.h> //I recommend you hover over the name an click "Open Document <x.h>" and ensure that it doesn't have "SCE CONFIDENTIAL" at the top of it, and if it does make sure you include the other filename with the same name and it should be it.
