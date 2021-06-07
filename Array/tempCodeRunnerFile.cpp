 int count=0;
        for(i=0;i<max+1;i++){
            if(a[i]>0)
                count++;
            if(count==k)
                break;
        }
        return i;