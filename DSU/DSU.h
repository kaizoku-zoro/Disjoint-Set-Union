//GitHub: kaizoku-zoro
#ifndef DSU_H
#define DSU_H
#include <vector>


class DSU
{
    public:

        DSU(int n)
        {
            countOfGroups = n;
            parents = std::vector<int>(n);
            ranks = std::vector<int>(n,1);
            for(int i = 0; i < n; i++)
                  parents[i] = i;
        }

        //add a new set to the DSU
        void MakeSet();

        //merge sets to which id1 and id2 belong
        void Union(int id1, int id2);

        //finds the representative element of the se to which id belongs
        int Find(int id);

        //returns the number of elements in the set to which id belongs
        int groupSize(int id);

        //return true if id belongs to a valid element
        bool isValidId(int id)
        {
            if(id >= 0 && id < parents.size())
                return 1;
            return 0;
        }

        //returns number of sets
        int getCountOfGroups()
        {
            return countOfGroups;
        }
    private:
        int countOfGroups;
        std::vector<int> parents;
        std::vector<int> ranks;
};
void DSU::MakeSet()
{
   countOfGroups++;
   int id = parents.size();
   parents.push_back(id);
   ranks.push_back(1);
}

void DSU::Union(int id1, int id2)
{
    if( !(isValidId(id1) && isValidId(id2)) )
        return;
    int group1 = Find(id1);
    int group2 = Find(id2);
    if(group1 == group2)
          return;
    countOfGroups--;
    if(ranks[group1] >= ranks[group2])
    {
        parents[group2] = group1;
        ranks[group1] += ranks[group2];
    }
    else
    {
        parents[group1] = group2;
        ranks[group2] += ranks[group1];
    }
}

int DSU::Find(int id)
{
   if(!isValidId(id))
      return -1;
   int parent = parents[id];
   if(parent == id)
      return parent;
   else return parents[id] = Find(parent);
}

int DSU::groupSize(int id)
{
    if(!isValidId(id))
      return -1;
    return ranks[Find(id)];
}

#endif // DSU_H
