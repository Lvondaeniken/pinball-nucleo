cmake_minimum_required(VERSION 3.19)

project(
  EmbeddedCMake
  VERSION 0.1
  LANGUAGES ASM C CXX
)

enable_language(C CXX ASM)

file(GLOB_RECURSE SRC 
	Core/*.[c|s] 
	Core/Src/main.cpp
  Core/Src/app.cpp
  Core/Src/bumper.cpp
  Core/Src/target.cpp
  Core/Src/switch.cpp
  Core/Src/coil.cpp
  Core/Src/ballshooter.cpp
  Core/Src/kicker.cpp
  Core/Src/slingshot.cpp
  Core/Src/log.cpp
  Core/Src/*.[c|cpp]
	Drivers/*.[c|cpp] 
)

add_executable(EmbeddedCMake ${SRC})

target_compile_definitions(EmbeddedCMake PRIVATE $<$<CONFIG:DEBUG>:DEBUG>
												USE_HAL_DRIVER STM32F0xx
												STM32F030x8)

target_include_directories(
	EmbeddedCMake PRIVATE 
	Core/Inc 
	Drivers/CMSIS/Device/ST/STM32F0xx/Include
	Drivers/CMSIS/Include 
	Drivers/STM32F0xx_HAL_Driver/Inc
	Drivers/STM32F0xx_HAL_Driver/Inc/Legacy
)

target_link_libraries(
  EmbeddedCMake
  PRIVATE --specs=nano.specs -Wl,--gc-sections,-Map=${PROJECT_NAME}.map
		  -T${CMAKE_CURRENT_SOURCE_DIR}/STM32F030R8TX_FLASH.ld)

# Create hex file
add_custom_command(TARGET EmbeddedCMake
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex EmbeddedCMake ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary EmbeddedCMake ${PROJECT_NAME}.bin)
