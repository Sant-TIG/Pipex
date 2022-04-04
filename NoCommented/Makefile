M	            = Mandatory/
B	            = Bonus/
C               = Common/

O	            = objs/
U               = utils/
CH              = check/
S               = strings/

NAME            = pipex
BONUS_NAME      = pipex_bonus

CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
FSANITIZE       = -fsanitize=address -g3

RM              = -rm -r

CHECK_FILES     = $(CH)ft_check_files
STRINGS_FILES   = $Sft_split $Sft_strlen $Sft_strncmp $Sft_strncpy $Sft_strndup $Sft_substr $Sft_strjoin $Sft_strlcat
UTILS_FILES     = $Uft_get_commands $Uft_get_commands_path $Uft_access_command

COMMON_FILES    = $(addprefix $C, $(CHECK_FILES)) $(addprefix $C, $(STRINGS_FILES)) $(addprefix $C, $(UTILS_FILES))
MANDATORY_FILES = $Mpipex
BONUS_FILES     = $Bpipex_bonus $B$Uft_get_next_line $B$Uft_get_next_line_utils

COMMON_SRCS     = $(addsuffix .c, $(COMMON_FILES))
MANDATORY_SRCS  = $(addsuffix .c, $(MANDATORY_FILES))
BONUS_SRCS      = $(addsuffix .c, $(BONUS_FILES))

all: $(NAME)

$(NAME): $(MANDATORY_SRCS) $(COMMON_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_SRCS) $(COMMON_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

fclean:
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all