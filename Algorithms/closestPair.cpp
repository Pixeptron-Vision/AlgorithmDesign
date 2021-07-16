#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
struct Point
{
    double x;
    double y;
    Point(double x_in, double y_in):x{x_in},y{y_in}{}
    Point(){}

};
template<typename T>
bool compare(T a1,T a2)
{
    if(a1 <= a2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool compareX(Point p1, Point p2)
{
    if(p1.x <= p2.x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool compareY(Point p1,Point p2)
{
    if(p1.y <= p2.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Merge Sort Functions*/

template<typename T>
T merge(T& arr1, T&arr2,std::function<bool(Point,Point)>compare_points)
{
  int total_length = arr1.size() + arr2.size();
  T res(total_length);
  int i{0},j{0},k{0};
  while(i< arr1.size() && j < arr2.size())
  {
    bool comparison_result = compare_points(arr1[i],arr2[j]);

    if(comparison_result)//(arr1[i] <= arr2[j])
    {
      res[k] = arr1[i];
      k++;
      i++;
    }
    else
    {
      res[k] = arr2[j];
      k++;
      j++;
    }
  }
  while( i < arr1.size() && k < total_length)
  {
    res[k]=arr1[i];
    k++;
    i++;
  }
  while(j < arr2.size() && k < total_length)
  {
    res[k]=arr2[j];
    k++;
    j++;
  }
  return res;
}
template<typename T>
void copyVec(T& arr1, T& arr2, int low, int high)
{
  for(int i=low, j=0; i<= high; i++,j++)
  {
    arr2[j] = arr1[i];
  }
}
template<typename T>
T mergeSort(T v, int low, int high,std::function<bool(Point,Point)>compare_points)
{
  int length = high-low+1;
  if(length < 2)
  {
    return v;
  }
  else
  {
    int mid = high / 2;
    // Create the left copy of vector
    T arr1(mid-low+1);
    T arr2(high-mid);
    auto it1 = v.begin();
    auto it2 = v.begin();
    it2 += mid+1;
    it1 +=mid+1;
    arr1.assign(v.begin(),it1);
    arr2.assign(it2,v.end());

    //copyVec(v,arr1,low,mid); //Not used as elements are copied using assign
    //copyVec(v,arr2,mid+1,high); //Not used as elements are copied using assign

    //cout<<" Low:- "<<low<<" High:- "<<high<<" Mid:- "<<mid<<endl;

    // first recursive call
    T left = mergeSort(arr1,low, mid,compare_points);
    T right = mergeSort(arr2,low,high-mid-1,compare_points);
    T result = merge(left, right,compare_points);
    return result;
  }

}
/* Closest pair functions*/
double distance(Point& p1, Point& p2)
{
    //cout<<"Distance In"<<endl;
    //cout<<p1.x<<" "<<p1.y<<";"<<p2.x<<" "<<p2.y<<endl;
    double x_diff = p1.x - p2.x ;
    double y_diff = p1.y - p2.y ;

    x_diff = pow(x_diff,2);

    y_diff = pow(y_diff,2);

    double dist = sqrt(x_diff + y_diff);
    //cout<<"Distance Out"<<endl;
    return dist;
}
template<typename T>
bool closestSplitPair(T Px,T Py,double delta,T& closestPair)
{
    //Determine the mid X

    int mid = (Px.size()-1)/2;
    double Xm = Px[mid].x;
    double Xm_d0 = Xm - (delta);
    double Xm_d1 = Xm + (delta);
    //cout<<delta<<" "<<Xm_d0<<" "<<Xm<<" "<<Xm_d1<<endl;
    // Filter the points sorted according to y-coordinate
    T Sy;
    for(int i=0;i<Py.size();i++)
    {
        double x = Py[i].x;
        if(x > Xm_d0 && x < Xm_d1)
        {
            Sy.push_back(Py[i]);
        }
    }
    // Find the closest pair in the filtered points
    int index1, index2;
    index1 = 0;
    index2 = 0;
    bool found = false;
    double shortestDistance=0;
    int iter_max=7;
    if(Sy.size() < 8)
    {
        iter_max = Sy.size();
    }
    for(int i=0;i<Sy.size()-1;i++)
    {
        for(int j=1;i+j<=iter_max;j++)
        {
            //cout<<Sy.size()<<"Checking "<<i<<" "<<j<<endl;
            double dist = distance(Sy[i],Sy[i+j]);
            if(dist < delta)
            {
                found = true;
                index1 = i;
                index2 = j;
                shortestDistance = dist;
            }
        }
    }
    if(found)
    {
        closestPair[0]=Sy[index1];
        closestPair[1]=Sy[index2];
        //Display(closestPair);

    }

    return found;

}
template<typename T>
T closestPairWork(T Px, T Py)
{
    int length = Px.size();
    T closestPair;
    if(length == 3)
    {
        double dist1 = distance(Px[0],Px[1]);
        double dist2 = distance(Px[1],Px[2]);
        double dist3 = distance(Px[0],Px[2]);
        if (dist1 < dist2 && dist1< dist3)
        {
            closestPair.push_back(Px[0]);
            closestPair.push_back(Px[1]);
        }
        else if(dist2 < dist1 && dist2< dist3)
        {
            closestPair.push_back(Px[1]);
            closestPair.push_back(Px[2]);
        }
        else if(dist3 < dist1 && dist3< dist1)
        {
            closestPair.push_back(Px[0]);
            closestPair.push_back(Px[2]);
        }
        //Display(closestPair);
        return closestPair;
    }
    else if(length ==2)
    {
        closestPair.push_back(Px[0]);
        closestPair.push_back(Px[1]);
        //Display(closestPair);
        return closestPair;
    }
    else
    {
        //Display(Px);
        //Display(Py);

        T Lx,Ly,Rx,Ry;
        int mid_x = (Px.size()-1)/2;
        int mid_y = (Py.size()-1)/2;
        Lx.assign(Px.begin(),Px.begin()+mid_x+1);
        Rx.assign(Px.begin()+mid_x+1,Px.end());
        Ly.assign(Py.begin(),Py.begin()+mid_y+1);
        Ry.assign(Py.begin()+mid_y+1,Py.end());

        T closestPairL = closestPairWork(Lx,Ly);
        double deltaL = distance(closestPairL[0],closestPairL[1]);
        T closestPairR = closestPairWork(Rx,Ry);
        double deltaR = distance(closestPairR[0],closestPairR[1]);
        double delta=10000000;
        bool left = false;
        if(deltaL < deltaR)
        {
            delta = deltaL;
            left = true;
            //Display(closestPairL);
        }
        else
        {
            delta = deltaR;
            //Display(closestPairR);
        }
        T closestPair(2);
        bool split = closestSplitPair(Px,Py,delta,closestPair);
        if(split)
        {
            //cout<<"Split True\n";
            //Display(closestPair);
            return closestPair;
        }
        else
        {
            if(left)
            {
                return closestPairL;
            }
            else
            {
                return closestPairR;
            }
        }
    }

}
template<typename T>
T closestPair(T points)
{
    T Px = mergeSort(points,0,points.size()-1,compareX);
    T Py = mergeSort(points,0,points.size()-1,compareY);
    T closestPair = closestPairWork(Px,Py);
    return closestPair;
}
template<typename T>
void Display(T a)
{
    cout<<"****************"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<"("<<a[i].x<<","<<a[i].y<<")"<<endl;
    }
    cout<<"****************"<<endl;
}
int main()
{
    vector<Point>v;
    int n=0;
    cout<<"Enter the length of array\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        Point p;
        p.x = x;
        p.y = y;
        v.push_back(p);
    }
    //vector<Point> s = mergeSort(v,0,v.size()-1,compareY);
    vector<Point> closestP = closestPair(v);
    cout<<"closest Pair:-\n";
    Display(closestP);


    return 0;
}
