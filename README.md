# Example Blink project using IDF and Arduino Esp32 as component

## Directory tree structure:

I recommend the following folder structure for the projects.

```
IDF_PROJECTS
├── arduino
├── IDF_Framework
└── Projects
    └── Blink
        ├── .vscode
        ├── components
        │   └── MyLibrary
        │       ├── CMakeLists.txt
        │       ├── lib.cpp
        │       └── lib.h
        ├── data
        │   └── example_spiffs_file.txt
        ├── main
        │   ├── CMakeLists.txt
        │   └── main.cpp
        ├── partitions.csv
        ├── sdkconfig
        └── ... Rest of folders and files ...
```

#### Notes:
The Arduino Framework folder NEEDS to be named just 'arduino,' not 'arduino-esp32' or something else. This is because most libraries, in their CMakeLists.txt files, use this: 'idf_component_register(....... REQUIRES arduino)'. So, if you change the name, no libraries will work.

This folder can also be placed in each project component folder, but I prefer to have it globally for all projects. Otherwise, every project will need to have the full framework. Still, this can be useful in case of any Arduino Framework version-specific dependency.


## Partitions table
By default, I'm using the same partition table as Arduino ESP32 for 4MB devices. However, this can be modified in partitions.csv. You can refer to partition_table_explanation.xlsx for explanations about sizes, offsets, names, and a basic calculator.

## OTA Uploads
To upload via OTA, we need to use `espota.exe` or `espota.py`, wich is located on ```arduino\tools```, for that we use the next commands:

For firmware:
```
.\espota.exe -i <esp_ip> -f PROJECT_DIRECTORY/build/ProjectName.bin
```
For spiffs:
```
.\espota.exe -i 192.168.1.95 -s -f -f PROJECT_DIRECTORY/build/spiffs.bin
```

Because I set this in `main/CMakeLists.txt`: `spiffs_create_partition_image(spiffs ../data FLASH_IN_PROJECT)`

`spiffs.bin` will be automatically generated when building, and even upload if we are flashing via serial.