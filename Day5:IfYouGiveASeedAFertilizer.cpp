#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll findEntryWithLargestValue(map<ll, ll> sampleMap)
{
    pair<ll, ll> entryWithMaxValue = make_pair(0, 0);
    map<ll, ll>::iterator currentEntry;
    for (currentEntry = sampleMap.begin(); currentEntry != sampleMap.end(); ++currentEntry)
    {
        if (currentEntry->second > entryWithMaxValue.second)
        {
            entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }
    return entryWithMaxValue.second;
}

int main()
{
    ll seeds[20];
    for (int i = 0; i < 20; i++)
    {
        cin >> seeds[i];
    }

    vector<ll> inp(3);
    vector<vector<ll>> seed2soil, soil2fer, fer2wtr, wtr2light, light2temp, temp2hum, hum2loc;
     map<ll, ll> m1, m2, m3, m4, m5, m6, m7;

    for (int i = 0; i < 36; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m1.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 24; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m2.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 34; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m3.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 46; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m4.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 29; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m5.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 30; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m6.insert({inp[1]++, inp[0]++});
        }
    }
    for (int i = 0; i < 38; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m7.insert({inp[1]++, inp[0]++});
        }
    }

    ll nearestLoc = findEntryWithLargestValue(m7);
    ll soil = nearestLoc, fertilizer = nearestLoc, water = nearestLoc, light = nearestLoc, temperature = nearestLoc, humidity = nearestLoc, location = nearestLoc;

    for (auto &seed : seeds)
    {
        soil = seed;
        if (m1.find(seed) != m1.end())
        {
            soil = m1[seed];
        }
        fertilizer = soil;
        if (m2.find(soil) != m2.end())
        {
            fertilizer = m2[soil];
        }
        water = fertilizer;
        if (m3.find(fertilizer) != m3.end())
        {
            water = m3[fertilizer];
        }
        light = water;
        if (m4.find(water) != m4.end())
        {
            light = m4[water];
        }
        temperature = light;
        if (m5.find(light) != m5.end())
        {
            temperature = m5[light];
        }
        humidity = temperature;
        if (m6.find(temperature) != m6.end())
        {
            humidity = m6[temperature];
        }
        location = humidity;
        if (m7.find(humidity) != m7.end())
        {
            location = m7[humidity];
        }
        nearestLoc = min(nearestLoc, location);
    }
    
    cout << nearestLoc;
}
