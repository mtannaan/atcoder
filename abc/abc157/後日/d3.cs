using System;


class UnionFind
{
    /// <summary>
    /// 正の値は親nodeを示す。
    /// 負の値は、そのnodeが根であることと、そのnodeを根とする木のサイズ * (-1) を示す。
    /// </summary>
    public int[] Data;

    public UnionFind(int nNodes=0){
        Data = new int[nNodes];
        for(int i=0; i<nNodes; i++){
            Data[i] = -1;
        };
    }

    /// <summary>
    /// iNode番目のノードが属する木の根の番号を返す。
    /// </summary>
    int FindRoot(int iNode){
        if(Data[iNode] < 0){
            return iNode;
        }else{
            return Data[iNode] = FindRoot(Data[iNode]);
        }
    }

    /// <summary>
    /// iNodeが属する木のサイズを返す
    /// </summary>
    public int Size(int iNode){
        return -Data[FindRoot(iNode)];
    }

    
    /// <summary>
    /// 2つの木をくっつける。
    /// くっつけたらtrue, すでに同一の木であればfalseを返す。
    /// </summary>
    public bool Unite(int i1, int i2){
        i1 = FindRoot(i1);
        i2 = FindRoot(i2);
        if(i1 == i2){
            return false;
        }

        // 木が深くならないように (深くなるとFindの計算量がふえる)、
        // サイズが小さい木をサイズが大きい木へマージする
        int iLarge, iSmall;
        if(i1 > i2){
            // i1, i2 はサイズ * (-1)を表す！
            iLarge = i2;
            iSmall = i1;
        }else{
            iLarge = i1;
            iSmall = i2;
        }
        Data[iLarge] += Data[iSmall];
        Data[iSmall] = iLarge;
        return true;
    }

    /// <summary>
    /// 2つのノードが同一の木に属しているか否かを返す
    /// </summary>
    public bool HasSameRoot(int i1, int i2){
        return FindRoot(i1) == FindRoot(i2);
    }
}

class Program
{
    static void Main(string[] args)
    {
        string[] nmk = Console.ReadLine().Split(' ');
        int 
        N = int.Parse(nmk[0]),
        M = int.Parse(nmk[1]),
        K = int.Parse(nmk[2]);

        UnionFind uf = new UnionFind(N);
        int[] nFriends = new int[N];
        for(int i=0; i<M; i++){
            string[] ab = Console.ReadLine().Split(' ');
            int a = int.Parse(ab[0]) - 1, b = int.Parse(ab[1]) - 1;
            nFriends[a]++;
            nFriends[b]++;
            uf.Unite(a, b);
        }

        int[] nBlockedCands = new int[N];
        for(int i=0; i<K; i++){
            string[] ab = Console.ReadLine().Split(' ');
            int a = int.Parse(ab[0]) - 1, b = int.Parse(ab[1]) - 1;
            if(uf.HasSameRoot(a, b)){
                nBlockedCands[a]++;
                nBlockedCands[b]++;
            }
        }

        for(int i=0; i<N; i++){
            Console.Write(uf.Size(i) - nFriends[i] - nBlockedCands[i] - 1 /* self */);
            Console.Write(i == N-1 ? '\n' : ' ');
        }
    }
}
