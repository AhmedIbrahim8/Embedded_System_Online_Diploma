#@copyright : Ahmed Ibrahim 
#@Date      : 5/9/2023

#Tool chain dependencies 
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS= -I .
LIBS=
SRC  = $(wildcard *.c)
OBJ  = $(SRC:.c=.o)
As   = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=toggle_led_cortex_m4

all: $(Project_name).bin
	@echo "=========Build is Done========"


%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS)  $< -o $@


$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
	
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean-all:
	rm *.map
	rm *.o
	rm *.bin
	rm *.elf
	

clean:
	rm .elf
	rm .bin