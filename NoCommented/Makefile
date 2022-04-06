M	            = Mandatory/
B	            = Bonus/
C               = Common/

O	            = objs/
U               = utils/
CH              = check/
S               = strings/
F               = free/

NAME            = pipex
BONUS_NAME      = pipex_bonus

CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
FSANITIZE       = -fsanitize=address -g3

RM              = -rm -r

CHECK_FILES     = $(CH)ft_check_files
FREE_FILES      = $Fft_general_free $Fft_free_2d_str $Fft_free_3d_str
STRINGS_FILES   = $Sft_split $Sft_strlen $Sft_strncmp $Sft_strncpy $Sft_strndup $Sft_substr $Sft_strjoin $Sft_strlcat
UTILS_FILES     = $Uft_get_commands $Uft_get_commands_path $Uft_access_command

COMMON_FILES    = $(addprefix $C, $(CHECK_FILES)) $(addprefix $C, $(STRINGS_FILES)) $(addprefix $C, $(UTILS_FILES)) $(addprefix $C, $(FREE_FILES))
MANDATORY_FILES = $Mpipex
BONUS_FILES     = $Bpipex_bonus $B$Uft_get_next_line $B$Uft_get_next_line_utils

COMMON_SRCS     = $(addsuffix .c, $(COMMON_FILES))
MANDATORY_SRCS  = $(addsuffix .c, $(MANDATORY_FILES)) $(addsuffix .c, $(COMMON_FILES))
BONUS_SRCS      = $(addsuffix .c, $(BONUS_FILES)) $(addsuffix .c, $(COMMON_FILES))

BONUS_OBJS      = $(addsuffix .o, $(BONUS_FILES)) $(addsuffix .o, $(COMMON_FILES))
MANDATORY_OBJS  = $(addsuffix .o, $(MANDATORY_FILES)) $(addsuffix .o, $(COMMON_FILES))
COMMON_OBJS     = $(addsuffix .o, $(COMMON_FILES))

all: mandatory bonus

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

mandatory: $(NAME)

$O%.o: $(MANDATORY_SRCS)%.c $(COMMON_SRCS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MANDATORY_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)


bonus: $(BONUS_NAME)

$O%.o: $(BONUS_SRCS)%.c $(COMMON_SRCS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_SRCS) $(COMMON_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME) $O

re: fclean all

.PHONY: fclean clean bonus mandatory all
