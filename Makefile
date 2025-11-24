# Header

# ***************************************************** #
# *                 Configuration                     * #
# ***************************************************** #

# MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= libunit.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD #more flags
DEBUGFLAGS	:=

DIR_BUILD	= .build
DIR_CONFIG	= framework/standards
DIR_INTERN	= _internal_

INCLUDES	:= -I$(DIR_CONFIG) -Iframework/core -Iframework/interface -Iframework/utils framework/interface/ft_printf -Iframework/memory

SRC			:=	framework/core/core.c framework/interface/interface.c framework/utils/utils.c \
				framework/interface/ft_printf/ft_printf.c framework/interface/ft_printf/interface.c \
				framework/interface/ft_printf/_internal/printf/writer.c framework/interface/ft_printf/_internal/utils/_utils.c \
				framework/memory/memory.c framework/memory/_internal_/_memory.c framework/memory/_internal_/_memory_utils.c
_SRC_ALL	:= $(SRC)

_OBJ		:= $(addprefix $(DIR_BUILD)/, $(_SRC_ALL:.c=.o))
_DEPS		:= $(_OBJ:.o=.d)

-include $(_DEPS)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header $(NAME)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

.PHONY:

$(NAME): $(_OBJ)
	ar rcs $(NAME) $(_OBJ)

$(DIR_BUILD):
	mkdir -p $@ $(DIR_BUILD)/_internal_
	mkdir -p $(dir $(_OBJ))

$(DIR_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c $< -o $@

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm $(_OBJ)

fclean:
	rm -rf $(DIR_BUILD) $(NAME)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs debug.pg

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)
	@echo "\033[1;33m DEBUG MODE ACTIVATED $(_RESET)"

debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

debug.pg:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -pg)


# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header install uninstall update

_YELLOW	:= \033[1;33m
_GREEN	:= \033[1;32m
_RED	:= \033[1;31m
_RESET	:= \033[0m

header:
ifeq ($(MAKELEVEL), 0)
	@echo "Big Fat Header"
endif

# -----| Install / Uninstall |----- #

INSTALL_DIR = $(HOME)/.local/bin
install:
	mkdir -p $(INSTALL_DIR)
	cp $(NAME) $(INSTALL_DIR)/
	chmod +x $(INSTALL_DIR)/$(NAME)
	$(call _completion)
	echo "$(_GREEN) ✅ $(NAME) installed to $(INSTALL_DIR) $(_RESET)"; \

uninstall:
	rm -rf $(INSTALL_DIR)/$(NAME)
	echo "$(_GREEN) ✅ $(NAME) uninstalled from $(INSTALL_DIR) $(_RESET)";

update:
	if [ -f ./auto.sh ]; then \
		echo "\033[1;33m Updating Makefile... $(_RESET)"; \
	else \
		echo "$(_RED) auto.sh not found, please add the script to automate the update $(_RESET)"; \
		exit 1; \
	fi
	./auto.sh
	echo "$(_GREEN) ✅ Makefile updated $(_RESET)";