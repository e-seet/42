# -=-=-=-=-	Basic -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t\tBasic input\t\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

# 1
ARG="2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}";
else
	printf "${RED}1.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}";
else
	printf "${RED}2.[KO]${DEF_COLOR}";
fi

# 2
ARG="1 3 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
	printf "${RED}3.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}";
else
	printf "${RED}4.[KO]${DEF_COLOR}";
fi

ARG="2 3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}";
else
	printf "${RED}5.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}6.[OK] ${DEF_COLOR}";
else
	printf "${RED}6.[KO]${DEF_COLOR}";
fi

ARG="2 1 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}7.[OK] ${DEF_COLOR}";
else
	printf "${RED}7.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}8.[OK] ${DEF_COLOR}";
else
	printf "${RED}8.[KO]${DEF_COLOR}";
fi

ARG="3 1 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}9.[OK] ${DEF_COLOR}";
else
	printf "${RED}9.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}10.[OK] ${DEF_COLOR}";
else
	printf "${RED}10.[KO]${DEF_COLOR}";
fi

ARG="3 2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}11.[OK] ${DEF_COLOR}";
else
	printf "${RED}11.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}12.[OK] ${DEF_COLOR}";
else
	printf "${RED}12.[KO]${DEF_COLOR}";
fi
ARG="1 2 4 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}13.[OK] ${DEF_COLOR}";
else
	printf "${RED}13.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi

S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}14.[OK] ${DEF_COLOR}";
else
	printf "${RED}14.[KO]${DEF_COLOR}";
fi

ARG="1 3 2 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}15.[OK] ${DEF_COLOR}";
else
	printf "${RED}15.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}16.[OK] ${DEF_COLOR}";
else
	printf "${RED}16.[KO]${DEF_COLOR}";
fi

ARG="1 3 4 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}17.[OK] ${DEF_COLOR}";
else
	printf "${RED}17.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}18.[OK] ${DEF_COLOR}";
else
	printf "${RED}18.[KO]${DEF_COLOR}";
fi

ARG="1 4 3 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}19.[OK] ${DEF_COLOR}";
else
	printf "${RED}19.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}20.[OK] ${DEF_COLOR}";
else
	printf "${RED}20.[KO]${DEF_COLOR}";
fi

ARG="1 4 2 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}21.[OK] ${DEF_COLOR}";
else
	printf "${RED}21.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}22.[OK] ${DEF_COLOR}";
else
	printf "${RED}22.[KO]${DEF_COLOR}";
fi

ARG="2 3 4 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}23.[OK] ${DEF_COLOR}";
else
	printf "${RED}23.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}24.[OK] ${DEF_COLOR}";
else
	printf "${RED}24.[KO]${DEF_COLOR}";
fi

ARG="2 4 3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}25.[OK] ${DEF_COLOR}";
else
	printf "${RED}25.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}26.[OK] ${DEF_COLOR}";
else
	printf "${RED}26.[KO]${DEF_COLOR}";
fi

ARG="2 1 4 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}27.[OK] ${DEF_COLOR}";
else
	printf "${RED}27.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}28.[OK] ${DEF_COLOR}";
else
	printf "${RED}28.[KO]${DEF_COLOR}";
fi

ARG="2 1 3 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}29.[OK] ${DEF_COLOR}";
else
	printf "${RED}29.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}30.[OK] ${DEF_COLOR}";
else
	printf "${RED}30.[KO]${DEF_COLOR}";
fi

ARG="2 3 1 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}31.[OK] ${DEF_COLOR}";
else
	printf "${RED}31.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}32.[OK] ${DEF_COLOR}";
else
	printf "${RED}32.[KO]${DEF_COLOR}";
fi

ARG="2 4 1 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}33.[OK] ${DEF_COLOR}";
else
	printf "${RED}33.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}34.[OK] ${DEF_COLOR}";
else
	printf "${RED}34.[KO]${DEF_COLOR}";
fi

ARG="3 4 1 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}35.[OK] ${DEF_COLOR}";
else
	printf "${RED}35.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}36.[OK] ${DEF_COLOR}";
else
	printf "${RED}36.[KO]${DEF_COLOR}";
fi

ARG="3 4 2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}37.[OK] ${DEF_COLOR}";
else
	printf "${RED}37.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}38.[OK] ${DEF_COLOR}";
else
	printf "${RED}38.[KO]${DEF_COLOR}";
fi

ARG="3 2 1 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}39.[OK] ${DEF_COLOR}";
else
	printf "${RED}39.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}40.[OK] ${DEF_COLOR}";
else
	printf "${RED}40.[KO]${DEF_COLOR}";
fi

ARG="3 1 2 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}41.[OK] ${DEF_COLOR}";
else
	printf "${RED}41.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}42.[OK] ${DEF_COLOR}";
else
	printf "${RED}42.[KO]${DEF_COLOR}";
fi

ARG="3 1 2 4";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}43.[OK] ${DEF_COLOR}";
else
	printf "${RED}43.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}44.[OK] ${DEF_COLOR}";
else
	printf "${RED}44.[KO]${DEF_COLOR}";
fi

ARG="3 2 4 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}45.[OK] ${DEF_COLOR}";
else
	printf "${RED}45.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}46.[OK] ${DEF_COLOR}";
else
	printf "${RED}46.[KO]${DEF_COLOR}";
fi

ARG="3 1 4 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}47.[OK] ${DEF_COLOR}";
else
	printf "${RED}47.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}48.[OK] ${DEF_COLOR}";
else
	printf "${RED}48.[KO]${DEF_COLOR}";
fi

ARG="4 1 2 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}49.[OK] ${DEF_COLOR}";
else
	printf "${RED}49.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}50.[OK] ${DEF_COLOR}";
else
	printf "${RED}50.[KO]${DEF_COLOR}";
fi

ARG="4 1 3 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}51.[OK] ${DEF_COLOR}";
else
	printf "${RED}51.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}52.[OK] ${DEF_COLOR}";
else
	printf "${RED}52.[KO]${DEF_COLOR}";
fi

ARG="4 2 1 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}53.[OK] ${DEF_COLOR}";
else
	printf "${RED}53.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}54.[OK] ${DEF_COLOR}";
else
	printf "${RED}54.[KO]${DEF_COLOR}";
fi

ARG="4 2 3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}55.[OK] ${DEF_COLOR}";
else
	printf "${RED}55.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}56.[OK] ${DEF_COLOR}";
else
	printf "${RED}56.[KO]${DEF_COLOR}";
fi

ARG="4 3 1 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}57.[OK] ${DEF_COLOR}";
else
	printf "${RED}57.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}58.[OK] ${DEF_COLOR}";
else
	printf "${RED}58.[KO]${DEF_COLOR}";
fi

ARG="4 3 2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}59.[OK] ${DEF_COLOR}";
else
	printf "${RED}59.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}60.[OK] ${DEF_COLOR}";
else
	printf "${RED}60.[KO]${DEF_COLOR}";
fi

rm -rf 0
