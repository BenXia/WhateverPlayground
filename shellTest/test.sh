#!/bin/bash

################################################
#该脚本只是起到辅助查找作用，请持质疑的态度使用#
################################################

############################
##change current directory
############################
if [ `echo $0 | grep -c  "/"` -gt 0 ];then
    cd ${0%/*}
fi

resultTempFile="`pwd`/findTeacherDuplicateCategoryTemp.txt"
rm ${resultTempFile}
touch ${resultTempFile}

#cd ..

PROJ=`find . -name '*.h'`

IFS="
"
for file in ${PROJ}
do
	interfaceLineNumbers=`cat "${file}" | awk '/@interface /{print NR}'`
	totalFileLineNumber=`cat "${file}" | wc -l`
	
    if [ "${interfaceLineNumbers}" == "" ]; then
        categoryNumber=0
    else
	    categoryNumber=`echo -e "${interfaceLineNumbers}" | wc -l`
    fi
	currentCategoryNumber=1

    echo ${file}:${categoryNumber}
	while [[ ${currentCategoryNumber} -le ${categoryNumber} ]]
	do
		startLine=`echo -e "${interfaceLineNumbers}" | sed -n ''${currentCategoryNumber}'p'`
		
		if [ ${currentCategoryNumber} -eq ${categoryNumber} ]; then
			endLine=${totalFileLineNumber}
		else
			endLine=`echo -e "${interfaceLineNumbers}" | sed -n ''$((currentCategoryNumber+=1))'p'`
		    ((endLine-=1))
		fi
	
		categorySection=`cat "${file}" | sed -n ''"${startLine}"','"${endLine}"'p'`
		className=`echo -e "${categorySection}" | sed -n '1p' | sed -n 's/@interface *\(.*\) *(\(.*\))/\1/p'`
        #categoryContent=`echo -e "${categorySection}" | sed 's/\/\*.*\*\// /g' | sed 's/\/\/.*/ /g' | sed '/^[ \t]*$/d' | sed '/@/d' | sed '/\/\*/,/\*\//d' | sed 's/[ \t]*([^)]*) *//g' | sed 's/:[^  ;]* */:/g' | sed 's/ //g'`
#categoryContent=`echo -e "${categorySection}" | sed 's/\/\*.*\*\// /g' | sed 's/\/\/.*/ /g' | sed '/^\s*$/d' | sed '/@/d' | sed '/\/\*/,/\*\//d'`
        echo "${categorySection}"
		categoryContent=`echo -e "${categorySection}" | sed 's/\/\*.*\*\// /g' | sed 's/\/\/.*/ /g' | sed '/^\s*$/d' | sed '/@/d' | sed '/\/\*/,/\*\//d'`
        echo Step1"${categoryContent}"
        categoryContent=`echo -e "${categoryContent}" | sed 's/\s*([^)]*)\s*//g' | sed 's/:[^ ;]*\s*/:/g' | sed 's/ //g'`
        echo Step2"${categoryContent}"
		funcName=""
		
		for line in ${categoryContent}
		do
			isStart=`echo -e "${line}" | sed -n '/^[+-]/p'`
			isEnd=`echo -e "${line}" | sed -n '/;/p'`
			if [ "${isStart}" != "" ]; then
				funcName=${isStart}
				if [ "${isEnd}" != "" ]; then
					echo -e "${className} ${funcName}" >> ${resultTempFile}
				fi
			else
				funcName="${funcName}""${line}"
				if [ "${isEnd}" != "" ]; then
					echo -e "${className} ${funcName}" >> ${resultTempFile}
				fi
			fi 
		done
	
		((currentCategoryNumber+=1))
	done
done
