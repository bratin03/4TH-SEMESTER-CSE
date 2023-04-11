#Bratin Mondal
#21CS10016
function prntree() 
{
    #Traversing through each node
    for (element in H)
    {
        if(element!="")
        {
        #finding self index, left child index, right child index
        id=H[element]
        lid=L[id]
        rid=R[id]
        #assigning string for left child, right child
        if(lid!=0)
        {
            lchild=K[lid]
        }
        if(lid==0)
        {
            lchild="-"
        }
        if(rid!=0)
        {
            rchild=K[rid]
        }
        if(rid==0)
        {
            rchild="-"
        }

        printf("%10s : ID = %3d Left Child = %-10s Right Child = %-10s\n",element,id,lchild,rchild)
        }
    }
    
}

function findroot() 
{
    for (element in P)
    {   #Searching for Root
        if(P[element]=="")
        {
            root_idx=element
        }
    }
    printf("The root node has ID %d and key \"%s\"\n",root_idx,K[root_idx]);
}

function inorder(n)
{   #Calling Left Node if exists
    if(L[n]!=0)
    {
        inorder(L[n])
    }
    printf("%10s",K[n])
    #Formatting for printing
    indexer++
    if(indexer%5==0)
    {
        printf("\n")
    }
    #Calling Right Node if exists
    if(R[n]!=0)
    {
        inorder(R[n])
    }
    
}


BEGIN{
    FS= "[:,]"#File Separator
    idx=1#Variable to be used for index assignment
    indexer=0#Variable for indexing during printing
    root_idx=0#Variable to store root index
    n=0 #Variable to store number of nodes
}

{
    if(NR==1)
    {
        n=$1#Reading number of nodes
    }
    
    if(NR!=1)
    {
        if($1!="")
        {#Setting the Parent node
        if(H[$1]==0)
        {
            H[$1]=idx
            K[idx]=$1
            P[idx]=""
            idx++

        }
    }
        if($2!="")
        {#Setting the Left Child      
            if(H[$2]==0)
            {
                H[$2]=idx
                K[idx]=$2
                idx++
            }
            L[H[$1]]=H[$2]
            P[H[$2]]=H[$1]
        }
        if($2=="")
        {
            L[H[$1]]=0
        }
        if($3!="")
        {#Setting the Right Child     
            if(H[$3]==0)
            {
                H[$3]=idx
                K[idx]=$3
                idx++
            }
            R[H[$1]]=H[$3]
            P[H[$3]]=H[$1] 
        }
        if($3=="")
        {
            R[H[$3]]=0
        }
        
    }
}
END{#Calling the functions
    printf("Going to read tree with %d nodes\n",n)
    prntree()
    printf("\n")
    findroot()
    printf("\n")
    inorder(root_idx)
    print("\n\nBye...\n")
}