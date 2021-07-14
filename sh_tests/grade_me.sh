print_status()
{
    if diff $1 $2 > /dev/null
        then printf "\033[1;32m   [OK]\033[m    |"
        else printf "\033[1;31m   [KO]\033[m    |"
    fi
    delete_if_has_not_diff $1 $2 $3
}

delete_if_has_not_diff()
{
    if diff $1 $2 > $3
        then rm -rf $1 $2 $3
    fi
}

run_case()
{
    export OUT_BASH="./out/$1/$2_out_bash.txt"
    export ERROR_BASH="./out/$1/$2_error_bash.txt"
    export CODE_BASH="./out/$1/$2_code_bash.txt"
    export OUT_MSH="./out/$1/$2_out_msh.txt"
    export ERROR_MSH="./out/$1/$2_error_msh.txt"
    export CODE_MSH="./out/$1/$2_code_msh.txt"
    export OUT_DIFF="./out/$1/$2_out_diff.txt"
    export ERROR_DIFF="./out/$1/$2_error_diff.txt"
    export CODE_DIFF="./out/$1/$2_code_diff.txt"

    $SH_1 ./groups/$1/$2 1> $OUT_BASH 2> $ERROR_BASH; echo $? > $CODE_BASH
    $SH_2 ./groups/$1/$2 1> $OUT_MSH 2> $ERROR_MSH; echo $? > $CODE_MSH
    printf "|  %-23s |" $2
    print_status $OUT_BASH $OUT_MSH $OUT_DIFF
    print_status $ERROR_BASH $ERROR_MSH $ERROR_DIFF
    print_status $CODE_BASH $CODE_MSH $CODE_DIFF
    printf "\n"
}

run_place()
{
    printf "+--------------------------------------------------------------+\n"
    printf "|          GROUP       ->         %-29s|\n"  $1
    printf "+--------------------------+-----------+-----------+-----------+\n"
    printf "|           FILE           |    OUT    |   ERROR   | EXIT CODE |\n"
    printf "+--------------------------+-----------+-----------+-----------+\n"
    mkdir ./out/$1/
    for file_1 in $(ls ./groups/$1/)
        do if [[ -d ./groups/$1/$file_1 ]]
            then\
                mkdir ./out/$1/$file_1/
                for file_2 in $(ls ./groups/$1/$file_1)
                    do run_case $1 $file_1/$file_2
                done
        else
            run_case $1 $file_1
        fi
    done
    printf "+--------------------------+-----------+-----------+-----------+\n\n"
}

clean_out_dir()
{
    rm -rf ./out
}

run()
{
    if [[ $1 ]]
        then export SH_1=$1
        else export SH_1="bash"
    fi
    if [[ $2 ]]
        then export SH_2=$2
        else export SH_2="../minishell"
    fi
    printf "Test\n\t1 -> $SH_1\n\t2 -> $SH_2\n"
    clean_out_dir
    mkdir out
    for dir_place in $(cd ./groups/; ls)
        do run_place $dir_place
    done
}

run $1 $2
