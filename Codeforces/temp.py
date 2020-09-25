inp =  str(input()).split(',')
print("\\begin{center}\n\\begin{tabular}{ |c|c| } \n\\hline")
for i in inp:
    tmp = i.split('=')
    print(tmp[0]+' & ' + tmp[1] + "\\\\")
    
print(" \\hline \n\\end{tabular} \n\\end{center}")