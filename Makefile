NAME	= my_defender

CC	= gcc

RM	= rm -rf

REDDARK	=   \033[31;2m
RED	    =	\033[31;1m
GREEN	=	\033[32;1m
YEL  	=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
RES	    =   \033[0m

SRC_DIR 	= 	defender/

SRC_FILES	= 	main.c 				\
				launch_game.c	\
				gameloop.c	\
				scene_manager.c	\
				/init/init_random.c	\
				/background/init_background.c	\
				/background/display_background.c	\
				/background/destroy_background.c	\
				/game/init_game.c	\
				/game/display_game.c	\
				/game/destroy_game.c	\
				/game/clock_restart.c	\
				/game/map/get_map.c	\
				/game/map/print_map.c	\
				/game/map/setup_map_entities.c	\
				/game/selection/init_selection.c	\
				/game/selection/display_selection.c	\
				/game/selection/destroy_selection.c	\
				/game/soldier/check_number_of_soldier.c	\
				/game/soldier/end_of_wave.c	\
				/game/soldier/free_soldier.c	\
				/game/soldier/init_soldier.c	\
				/game/soldier/display_soldier.c	\
				/game/soldier/soldier_life.c	\
				/game/tower/focus_on_enemys.c	\
				/game/tower/add_tower.c	\
				/game/tower/range.c	\
				/game/tower/projectiles.c	\
				/game/tower/free_tower.c	\
				/event/event.c	\
				/event/click_manager.c	\
				/event/click_game.c	\
				/menu/init_menu.c	\
				/menu/display_menu.c	\
				/menu/destroy_menu.c	\
				/info/init_info.c	\
				/info/destroy_info.c	\
				/pause/init_pause.c	\
				/pause/display_pause.c	\
				/pause/destroy_pause.c	\
				/music/init_music.c	\
				/music/destroy_music.c	\
				/option/init_option.c	\
				/option/display_option.c	\
				/option/destroy_option.c	\
				/utils/mouse_resize.c	\
				/utils/tab_size.c	\
				/utils/add_block.c	\
				/utils/draw_many_text.c	\
				/help/init_help.c	\
				/help/display_help.c	\
				/help/step_help.c	\
				/help/destroy_help.c

SRC		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS	= $(SRC:.c=.o)

CFLAGS 	= -I ./include/
CFLAGS 	+= -Wall -Wextra -L./lib -lmy -g -lm

CSFMLFLAGS  =	-lcsfml-graphics -lcsfml-audio
CSFMLFLAGS += -lcsfml-window -lcsfml-system

all: start $(NAME)

$(NAME): $(OBJS)
	@echo -e " [$(RED)BINARY FILES$(RES)]        $(GREEN)DONE$(RES)"
	@make --no-print-directory -sC lib/
	@echo -e " [$(RED)COMPILE LIBRARY$(RES)]     $(GREEN)DONE$(RES)"
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS) $(CSFMLFLAGS)
	@echo -e " [$(RED)COMPILE BINARY$(RES)]      $(GREEN)DONE$(RES)"
#	@make --no-print-directory clean
#	@echo -e " [$(RED)CLEAN$(RES)]               $(GREEN)DONE$(RES)"
	@echo -e "-----------------------------------------------------"
	@echo -e "                 $(YEL)$(NAME)$(RES)                 "


start:
	@echo -e " [$(RED)START$(RES)]"
	@echo -e "-----------------------------------------------------"

clean:
	@$(RM) $(OBJS)
	@$(RM) vgcore*

fclean: clean
	@$(RM) $(NAME)
	@echo -e " [$(RED)FCLEAN$(RES)]              $(GREEN)DONE$(RES)"

re: start fclean all

%.o:	%.c
	@gcc $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re
