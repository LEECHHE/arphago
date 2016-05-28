albums = """1967 DavidBowie
1969 SpaceOddity
1970 TheManWhoSoldTheWorld
1971 HunkyDory
1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars
1973 AladdinSane
1973 PinUps
1974 DiamondDogs
1975 YoungAmericans
1976 StationToStation
1977 Low
1977 Heroes
1979 Lodger
1980 ScaryMonstersAndSuperCreeps
1983 LetsDance
1984 Tonight
1987 NeverLetMeDown
1993 BlackTieWhiteNoise
1995 1.Outside
1997 Earthling
1999 Hours
2002 Heathen
2003 Reality
2013 TheNextDay
2016 BlackStar""".split('\n')

for idx, text in enumerate(albums):
    album = text.split()
    album[0] = int(album[0])
    albums[idx] = album

Q = input()
for qi in range(Q):
    S, E = map(int, raw_input().split())
    result = []
    for album in albums:
        if S <= album[0] and album[0] <= E:
            result.append(album)

    print len(result)
    for album in result:
        print album[0], album[1]