RAYLIB_SOURCES	:=	raylib/sources/raylib/src
RAYLIB_LIB		:=	raylib/lib

all:
	@echo "Making raylib..."
	@$(MAKE) -C $(RAYLIB_SOURCES)
	@cp $(RAYLIB_SOURCES)/libraylib.a $(RAYLIB_LIB)/libraylib.a
	@echo "Finished making raylib"

clean:
	@$(MAKE) -C $(RAYLIB_SOURCES) clean

fclean:	clean
	@$(MAKE) -C $(RAYLIB_SOURCES) clean
	@$(RM) -f $(RAYLIB_LIB)/libraylib.a

re:	fclean all

.PHONY: all clean fclean re