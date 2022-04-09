M	            = mandatory/srcs/
B	            = bonus/srcs/
OM              = mandatory/mandatory_objs/
OB              = bonus/bonus_objs/

NAME            = pipex
BONUS_NAME      = pipex_bonus

CC              = gcc -g
CFLAGS          = -Wall -Werror -Wextra
FSANITIZE       = -fsanitize=address -g3

RM              = -rm -r

CHECK_FILES         = ft_check_files ft_treat_multiple_cmds ft_treat_one_cmd
FREE_FILES          = ft_general_free ft_free_2d_str ft_free_3d_str
STRINGS_FILES       = ft_split ft_strlen ft_strncmp ft_strncpy ft_strndup ft_substr ft_strjoin ft_strlcat
UTILS_FILES         = ft_get_commands ft_get_commands_path ft_access_command ft_process ft_cmd ft_process_final
MAIN_FILE           = pipex

BONUS_CHECK_FILES   = ft_check_files_bonus ft_treat_multiple_cmds_bonus ft_treat_one_cmd_bonus
BONUS_FREE_FILES    = ft_general_free_bonus ft_free_2d_str_bonus ft_free_3d_str_bonus
BONUS_STRINGS_FILES = ft_split_bonus ft_strlen_bonus ft_strncmp_bonus ft_strncpy_bonus ft_strndup_bonus ft_substr_bonus ft_strjoin_bonus ft_strlcat_bonus
BONUS_UTILS_FILES   = ft_get_commands_bonus ft_get_commands_path_bonus ft_access_command_bonus ft_process_bonus ft_treat_here_doc_bonus ft_cmd_bonus ft_process_final_bonus
BONUS_GNL_FILES     = ft_get_next_line_bonus ft_get_next_line_utils_bonus
BONUS_MAIN_FILE     = pipex_bonus

MANDATORY_OBJS  = $(addprefix $(OM), $(addsuffix .o, $(MAIN_FILE))) $(addprefix $(OM),$(addsuffix .o, $(CHECK_FILES))) $(addprefix $(OM),$(addsuffix .o, $(FREE_FILES))) $(addprefix $(OM),$(addsuffix .o, $(STRINGS_FILES))) $(addprefix $(OM),$(addsuffix .o, $(UTILS_FILES)))
BONUS_OBJS      = $(addprefix $(OB), $(addsuffix .o, $(BONUS_MAIN_FILE))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_CHECK_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_FREE_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_GNL_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_STRINGS_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_UTILS_FILES)))

MANDATORY_SRCS  = $(addprefix $(M), $(addsuffix .c, $(MAIN_FILE))) $(addprefix $(M),$(addsuffix .c, $(CHECK_FILES))) $(addprefix $(M),$(addsuffix .c, $(FREE_FILES))) $(addprefix $(M),$(addsuffix .c, $(STRINGS_FILES))) $(addprefix $(OM),$(addsuffix .c, $(UTILS_FILES)))
BONUS_SRCS      = $(addprefix $(B), $(addsuffix .c, $(BONUS_MAIN_FILE))) $(addprefix $(B),$(addsuffix .c, $(BONUS_CHECK_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_FREE_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_GNL_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_STRINGS_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_UTILS_FILES)))

all: mandatory bonus

mandatory: $(NAME)

$(OM):
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(MANDATORY_OBJS): | $(OM)

$(MANDATORY_OBJS): $(OM)%.o: $M%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

bonus: $(BONUS_NAME)

$(OB):
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(BONUS_OBJS): | $(OB)

$(BONUS_OBJS): $(OB)%.o: $B%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

clean:
ifeq ($(shell test -e bonus/bonus_objs/pipex_bonus.o && echo "0"), $(shell echo "0"))
	$(RM) $(BONUS_OBJS)
endif
ifeq ($(shell test -e mandatory/mandatory_objs/pipex.o && echo "0"), $(shell echo "0"))
	$(RM) $(MANDATORY_OBJS)
endif

fclean: clean
ifeq ($(shell test -e pipex_bonus && echo "0"), $(shell echo "0"))
	$(RM) $(BONUS_NAME) $(OB)
endif
ifeq ($(shell test -e pipex && echo "0"), $(shell echo "0"))
	$(RM) $(NAME) $(OM)
endif

re: fclean all

.PHONY: fclean clean mandatory bonus all