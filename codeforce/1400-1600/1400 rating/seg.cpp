#include<bits/stdc++.h>
using namespace std;

void updateParent(int ind, vector<int> &seg){
    if( ind == 0){
        seg[ind] = max( seg[ind*2 + 1], seg[2*ind + 2] );
        return;
    }
    seg[ind] = max( seg[ind*2 + 1], seg[2*ind + 2] );
    int pInd = (ind-1)/2;
    updateParent(pInd, seg);
}

void pointUpdate(int l, int r, int ind, int i, int val, vector<int> &seg){
    if( l == i && r == i){
        seg[ind] = val;
        updateParent((ind-1)/2, seg);
        return;
    }
    int mid = (l+r)/2;
    if( i <= mid){
        pointUpdate(l,mid,2*ind+1,i,val,seg);
    }else{
        pointUpdate(mid+1,r,2*ind+2,i,val,seg);
    }
}

int maxRangeQuery(int l, int r,int ql, int qr, vector<int> &seg, int ind){
    //  no overlapping
    if(qr < l || ql > r ) return INT_MIN;

    // completely inside...
    if(ql <= l && r <= qr) return seg[ind];

    // partial 
    int mid = (l+r)/2;

    int leftMax  = maxRangeQuery(l,mid,ql,qr,seg, 2*ind+1);
    int rightMax = maxRangeQuery(mid+1,r,ql,qr,seg, 2*ind+2);
    
    return max(leftMax, rightMax);
}


void setSeg(int l, int r,int ind, vector<int> &seg, vector<int> &arr){
    if( l > r) return;
    if( l == r){
        seg[ind] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    setSeg(l,mid,ind*2+1,seg,arr);
    setSeg(mid+1,r,ind*2+2,seg,arr);

    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    return;
}

int main(){
    cout << "Please enter array Information >> \n";
    cout << "Size of array >> ";
    int n; cin >> n;
    vector<int> v(n);
    cout << "Enter all " <<  n << " elements of array >> ";
    for(int i = 0 ; i<n ; i++) cin >> v[i];

    vector<int> seg(4*n, INT_MIN);

    // child --> parent * 2 + 1  , parent * 2 + 2
    
    cout << "\nBuilding Max Range Segment Tree :: :: :: :: :: \nSegment Tree structure completed\n\n";
    setSeg(0,n-1,0,seg,v);

    cout << "Start Your Query \n\n";
    bool flag = true;
    do{
        cout << "\nType of Query (1 or 2): ";
        int type; cin >> type;

        if( type == 1){
            cout << "Enter the range(l,r) for maxRange >> ";
            int ql,qr; cin >> ql >> qr;
            if(ql > qr) swap(ql,qr);
            ql = max(0,ql);
            qr = min(n-1, qr);
            cout << "Max for the given range is >> ";
            cout << maxRangeQuery(0,n-1,ql,qr,seg, 0) << endl;
        }else{
            int i, val; 
            
            do{
                cout << "please enter value and valid index between 0 to n-1 >> ";
                cin>> i >> val;
            }while(i < 0 || i >= n);
            
            pointUpdate(0,n-1,0,i,val,seg);
            cout << "Updation done in tree\n";
        }
        char c;
        cout << "\nWants to query more ? press(y) else any other key >> ";
        cin >> c;
        if(c != 'y' && c != 'Y'){
            cout << "Confirm again to exit";
            cin >> c;
        }

        if( c != 'y' && c != 'Y') flag = false;
    }while(flag);



}