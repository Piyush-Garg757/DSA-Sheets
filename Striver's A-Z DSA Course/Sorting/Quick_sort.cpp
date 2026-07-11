/*ismein hota basically ye hai ki hum ek pivot select karte hain, vo pivot koi bhi element ho sakta hai chahe 1st hi ya last ho ya chahe beech ka koi bhi ho use select karte hain aur fir use uski sahi jaagh pe place kkarte hain aur fir us se saare chote elements uske left side pe aur bade uske right pe place karte hain su fir uss ellment ko partiton keh dete hain fir partiton se pehlevale aur baad vale elements pe same procedure lagate hain*/
#include <iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivot = a[low], i = low, j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i < high)
            i++;
        while (a[j] > pivot && j > low)
            j--;
        if (i < j)
            a[i] = a[j] + a[i] - (a[j] = a[i]);
    }
    a[low] = a[low] + a[j] - (a[j] = a[low]);
    return j;
}
void qs(int a[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(a, low, high);
        qs(a, low, partition_index - 1);
        qs(a, partition_index + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// TC - O(nlog n)   SC - O(1)

// when already sorted or reversed sorted   thi scan be O(n^2)  so we use randomised quick sort
#include <iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivot_idx = low + rand() % (high - low + 1);
    swap(a[low], a[pivot_idx]);
    int pivot = a[low], i = low, j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i < high)
            i++;
        while (a[j] > pivot && j > low)
            j--;
        if (i < j)
            a[i] = a[j] + a[i] - (a[j] = a[i]);
    }
    a[low] = a[low] + a[j] - (a[j] = a[low]);
    return j;
}
void qs(int a[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(a, low, high);
        qs(a, low, partition_index - 1);
        qs(a, partition_index + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// This is always nlogn   and we do nothing just choose a ranodn idx as pivot idx between high and low and then swap it with a[low] so that it worka in order