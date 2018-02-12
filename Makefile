all:
	@make -C client
	@make -C server

clean:
	@make clean -C client
	@make clean -C server

fclean:
	@make fclean -C client
	@make fclean -C server
	
re:	fclean all

.PHONY:				all clean fclean re
