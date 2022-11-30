# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   STD-Expension - General.mk                      #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Wed Nov 30 22:05:39 CET 2022      #
#      ||  '-'                                                          #
# ********************************************************************* #

#       /\\                                                          
#      /  \\    CAUTION: Dont touch below unless you know what you   
#     / || \\      are doing! If you think it needs improvement,     
#    /  ..  \\     feels free to make a Pull Request. Thanks :)      
#   /========\\                                                      



a: all
everything: all
all: $(NAME)

ac: allclean
allc: allclean
allclean: libclean fullclean packageclean

tc: trueclean
truec: trueclean
trueclean: allclean dependclean

re: remake
remake: fullclean all

ra: remakeall
remakeall: allclean all

ifneq ($(NAME), run)
r: run
run: all
else
t: test
test: all
endif
	@./$(NAME) $(ARGUMENTS)



#####   RUINS   #####
# Old artifact used for making loading bars
# Its left as a remain in case I want to reimplement them better..

CMP_WORK_CT	= $(MSG_WORK) [$(CMP_COUNT) / $(CMP_TOTAL)] Compiling $@ ... $(MSG_NRET)
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(SRC)")
CMP_COUNT	= 0

#	@$(CMD_PRINT) $(CMP_WORK_CT) $(SILENT_TS)
#	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
