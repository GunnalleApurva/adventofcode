#include <bits/stdc++.h>
using namespace std;
#define ll long long 

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
    for (int i = 0; i < 36; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        seed2soil.push_back(inp);
    }
    for (int i = 0; i < 24; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        soil2fer.push_back(inp);
    }
    for (int i = 0; i < 34; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        fer2wtr.push_back(inp);
    }
    for (int i = 0; i < 46; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        wtr2light.push_back(inp);
    }
    for (int i = 0; i < 29; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        light2temp.push_back(inp);
    }
    for (int i = 0; i < 30; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        temp2hum.push_back(inp);
    }
    for (int i = 0; i < 38; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        hum2loc.push_back(inp);
    }
    map<ll, ll> m1, m2, m3, m4, m5, m6, m7;

    for (int i = 0; i < seed2soil.size(); i++)
    {
        for (int j = 0; j < seed2soil[i][2]; j++)
        {
            m1.insert({seed2soil[i][1], seed2soil[i][0]});
            seed2soil[i][0]++;
            seed2soil[i][1]++;
        }
    }
    for (int i = 0; i < soil2fer.size(); i++)
    {
        for (int j = 0; j < soil2fer[i][2]; j++)
        {
            m2.insert({soil2fer[i][1], soil2fer[i][0]});
            soil2fer[i][0]++;
            soil2fer[i][1]++;
        }
    }
    for (int i = 0; i < fer2wtr.size(); i++)
    {
        for (int j = 0; j < fer2wtr[i][2]; j++)
        {
            m3.insert({fer2wtr[i][1], fer2wtr[i][0]});
            fer2wtr[i][0]++;
            fer2wtr[i][1]++;
        }
    }
    for (int i = 0; i < wtr2light.size(); i++)
    {
        for (int j = 0; j < wtr2light[i][2]; j++)
        {
            m4.insert({wtr2light[i][1], wtr2light[i][0]});
            wtr2light[i][0]++;
            wtr2light[i][1]++;
        }
    }
    for (int i = 0; i < light2temp.size(); i++)
    {
        for (int j = 0; j < light2temp[i][2]; j++)
        {
            m5.insert({light2temp[i][1], light2temp[i][0]});
            light2temp[i][0]++;
            light2temp[i][1]++;
        }
    }
    for (int i = 0; i < temp2hum.size(); i++)
    {
        for (int j = 0; j < temp2hum[i][2]; j++)
        {
            m6.insert({temp2hum[i][1], temp2hum[i][0]});
            temp2hum[i][0]++;
            temp2hum[i][1]++;
        }
    }
    for (int i = 0; i < hum2loc.size(); i++)
    {
        for (int j = 0; j < hum2loc[i][2]; j++)
        {
            m7.insert({hum2loc[i][1], hum2loc[i][0]});
            hum2loc[i][0]++;
            hum2loc[i][1]++;
        }
    }

    ll nearestLoc = findEntryWithLargestValue(m7);

    ll soil = nearestLoc, fertilizer = nearestLoc, water = nearestLoc, light = nearestLoc, temperature = nearestLoc, humidty = nearestLoc, location = nearestLoc;

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
        humidty = temperature;
        if (m6.find(temperature) != m6.end())
        {
            humidty = m6[temperature];
        }
        location = humidty;
        if (m7.find(humidty) != m7.end())
        {
            location = m7[humidty];
        }
        nearestLoc = min(nearestLoc, location);
    }
    
    cout << nearestLoc;
}
