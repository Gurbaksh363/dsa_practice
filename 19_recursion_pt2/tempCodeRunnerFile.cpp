nt mid = start + (end-start)/2;
    if (arr[mid] == target) return mid;
    else if(arr[mid]>target){
      binarySearch(arr, start, mid-1, target);
    } else{
      binarySearch(arr, mid+1, end, target);
    }