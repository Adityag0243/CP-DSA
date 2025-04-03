
    }

    // cout <<"Outside enemy.... \n";


    queue< tuple<int, int, int> > me;

    l(i,0,n){
        l(j,0,m){
            if(map_[i][j] == 'A'){
                me.push(make_tuple(i,j,0));
                timer[i][j] = 0;
                break;
            }
        }
    }


    pair<int, int> start = {-1,-1};



    
    l(i,0,n){
        l(j,0,m){
            cout << timer[i][j] << "  ";
        }
        cout << endl;
    }


    cout<<endl;

    bool flag = false;
    while( !me.empty() ){

        auto it = me.front();   me.pop();
        
        int i = get<0>(it);
        int j = get<1>(it);
        int t = get<2>(it);
        timer[i][j] = (-t);

