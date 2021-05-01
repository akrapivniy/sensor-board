CC      = sdcc
LD      = sdcc

CFLAGS		= -mstm8 --code-size 8192
LDFLAGS		= -lstm8 --code-size 8192
SOURCES = utils rtc nrf24 i2c smesh_device shtc3 main ssd1306
OBJECTS=$(SOURCES:=.rel)


all: generate_uuid full

full: $(SOURCES)
	@ echo "[Linking]"
	$(LD)  -lstm8 -mstm8 --opt-code-size --code-size 8192 --iram-size 1024 --out-fmt-ihx $(OBJECTS) -o main.ihx


.c:  $(OBJECTS)
	@ echo "[Compiling main code] "
	$(CC) -lstm8 -mstm8 --opt-code-size -DSTM8 -I../stm8-lib/ -c $< -o $@.rel

clean:
	rm -f $(OBJECTS) *.hex *.map *.cdb *.ihx *.lk *.lst *.rel *.rst *.sym *.asm

generate_uuid:
	./generate_smesh_uuid

prog: test
	./stm8flash -cstlink -pstm8l051f3 -w $(OBJECT).ihx

