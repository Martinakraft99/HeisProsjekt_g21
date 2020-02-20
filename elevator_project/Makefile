

# konstanter for kildemappe, kilder, byggemappe og objektfiler
# patsubst tar inn et mønster som blir applisert med substitusjon i en tekst
SOURCE_DIR := source
SOURCES := main.c start_system.c hardware_input.c elevator_state.c motor_state.c request.c 
BUILD_DIR := build
OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES) )

DRIVER_ARCHIVE := $(BUILD_DIR)/libdriver.a
DRIVER_SOURCE := hardware.c io.c

# kompilatortype gcc med flagga vi bruker
# -O0 skal optimalisere for kompileringstid
CC := gcc
CFLAGS := -O0 -g3 -Wall -Werror -std=c11 -I $(SOURCE_DIR)
LDFLAGS := -L $(BUILD_DIR) -ldriver -lcomedi



.DEFAULT_GOAL := elevator
# programmet vårt! målet er elevator

# avhenger av OBJ og at DRIVER_ARCHIVE eksisterer (denne er for å få heisen til å fungere)
# gcc -O0 -g3 -wall -Werror -std=cll -I source
elevator : $(OBJ) | $(DRIVER_ARCHIVE)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)



# hvis ikke mappen build finnes fra før, lag build med undermappe driver (-p: parent directory lages også)
$(BUILD_DIR) :
	mkdir -p $@/driver

# objektfilene i build/%.o avhenger av kildefilene i source/%.c og at build eksisterer
# hver av kildefilene kompileres med
# gcc -O0 -g3 -Wall -Werror -std=c11 -I source -c $("første element") -o $("målet")
$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# objektfilene i build/driver/%.o avhenger av kildefilene i source/driver/%.c og at build eksisterer
# kildefilene kompileres til målet
$(BUILD_DIR)/driver/%.o : $(SOURCE_DIR)/driver/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 
$(DRIVER_ARCHIVE) : $(DRIVER_SOURCE:%.c=$(BUILD_DIR)/driver/%.o)
	ar rcs $@ $^

.PHONY: clean
clean :
	rm -rf $(BUILD_DIR) elevator
