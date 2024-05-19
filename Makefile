CC 				= cc
FLAGS 			=	-Wall -Wextra -Werror
ClIENT 			= client.c
SERVER 			= server.c
CNAME 			= client
SNAME 			= server
HELPER 			= minitalk_helper.c
BONUS_HELPER 	= minitalk_helper.c
BONUS_ClIENT 	= client_bonus.c
BONUS_SERVER 	= server_bonus.c
BONUS_CNAME 	= client_bonus
BONUS_SNAME 	= server_bonus

all: $(CNAME) $(SNAME)

$(CNAME): $(ClIENT)
	$(CC) $(FLAGS) $(ClIENT) $(HELPER) -o $(CNAME)

$(SNAME): $(SERVER)
	$(CC) $(FLAGS) $(SERVER) $(HELPER) -o $(SNAME)

bonus:
	$(CC) $(FLAGS) $(BONUS_ClIENT) $(BONUS_HELPER) -o $(BONUS_CNAME)
	$(CC) $(FLAGS) $(BONUS_SERVER) $(BONUS_HELPER) -o $(BONUS_SNAME)
clean:
	rm -f $(CNAME) $(SNAME)
	rm -f $(BONUS_CNAME) $(BONUS_SNAME)
fclean: clean

re: fclean all
