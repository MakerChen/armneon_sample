TARGET			= app_neon_sample
INC_DIR			= .
LIB_DIR			= .
LIBNAME			= m

NON_ARM_SIMU = 1

ifdef NON_ARM_SIMU
# NEON_2_SSE.h => https://github.com/intel/ARM_NEON_2_x86_SSE
COMPILER_PREFIX	=
CFLAGS			= -march=nehalem -mpopcnt -fPIC
USRDEFS			= -D_INTEL_SIMU_ -DNEON2SSE_DISABLE_PERFORMANCE_WARNING
else
COMPILER_PREFIX	= aarch64-linux-
CFLAGS			= -mcpu=cortex-a73.cortex-a53 -fno-aggressive-loop-optimizations -fPIC
endif

CC				= $(COMPILER_PREFIX)gcc
CINCS			= -I./ -I$(INC_DIR)
LINCS			= -L./ -L$(LIB_DIR)
CFLAGS			+= -Wall -O3
# CFLAGS			+= -pg
LDFLAGS			= $(foreach libname, $(LIBNAME), -l$(libname))
USRDEFS			+=

TMP_OBJ_FOLDER	= tmp
TMP_ASM_FOLDER	= asm
OBJECTS			= $(patsubst %.c, $(TMP_OBJ_FOLDER)/%.o, $(wildcard *.c))

all: $(OBJECTS)
	@$(CC) $(OBJECTS) $(LINCS) $(LDFLAGS) $(CINCS) $(CFLAGS) $(USRDEFS) -o $(TARGET)

$(TMP_OBJ_FOLDER)/%.o: %.c | $(TMP_OBJ_FOLDER)
	@$(CC) -c $^ $(LINCS) $(LDFLAGS) $(CINCS) $(CFLAGS) $(USRDEFS) -o $@

$(TMP_OBJ_FOLDER):
	@echo "Create $(TMP_OBJ_FOLDER) for object file"
	-@mkdir -p $(TMP_OBJ_FOLDER)

$(TMP_ASM_FOLDER):
	@echo "Create $(TMP_ASM_FOLDER) for object file"
	-@mkdir -p $(TMP_ASM_FOLDER)

test: all
	@./$(TARGET)

clean:
	@$(RM) $(TMP_OBJ_FOLDER)/*.o $(TMP_ASM_FOLDER)/*.s -f

cleanall: clean
	@$(RM) $(TARGET) -f
	@$(RM) $(TMP_OBJ_FOLDER) -rf
	@$(RM) $(TMP_ASM_FOLDER) -rf

.PHONY: all test clean cleanall
.DEFAULTGOAL: all
