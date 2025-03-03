
import subprocess
import os
import sys

def testAlphabeticalSortOnTitle():
    result = subprocess.run(["./genres", "temp.csv"],input= "7\n1\n3\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    outputToMatch = "Mr. Nobody\nDirector: Jaco Van Dormael\nActors: Jared Leto * Sarah Polley * Diane Kruger * Linh Dan Pham\nYear: 2009 Rating: 7.9 Meta Score: 63\nDescription: A boy stands on a station platform as a train is about to leave. Should he go with his mother or stay with his father? Infinite possibilities arise from this decision. As long as he doesn't choose anything is possible.\nWould you like to select another movie(y/n)?"
    if outputToMatch not in result.stdout:
        print("Alphabetical title sort failed.")
        return 0
    else:
        return 3
#before sort Ragussis (imperium) Dormael (mr nobody) sorrentino (youth) haynes (carol)
#order should be Mr. Nobody, Carol, Imperium, Youth
# def testAlphabeticalSortOnDirectorLast():
#     result = subprocess.run(["./genres", "temp.csv"],input= "7\n2\n1\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
#     outputToMatch = "Mr. Nobody\nDirector: Jaco Van Dormael\nActors: Jared Leto * Sarah Polley * Diane Kruger * Linh Dan Pham\nYear: 2009 Rating: 7.9 Meta Score: 63\nDescription: A boy stands on a station platform as a train is about to leave. Should he go with his mother or stay with his father? Infinite possibilities arise from this decision. As long as he doesn't choose anything is possible.\nWould you like to select another movie(y/n)?"
#     if outputToMatch not in result.stdout:
#         print("Alphabetical director last name sort failed.")
#         return 0
#     else:
#         return 2

def testNumericalYearSort(): #ascending
    result = subprocess.run(["./genres", "temp.csv"],input= "7\n2\n1\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    outputToMatch = "Mr. Nobody\nDirector: Jaco Van Dormael\nActors: Jared Leto * Sarah Polley * Diane Kruger * Linh Dan Pham\nYear: 2009 Rating: 7.9 Meta Score: 63\nDescription: A boy stands on a station platform as a train is about to leave. Should he go with his mother or stay with his father? Infinite possibilities arise from this decision. As long as he doesn't choose anything is possible.\nWould you like to select another movie(y/n)?"
    print(result)
    print("-----------")
    print(outputToMatch)
    if outputToMatch not in result.stdout:
        print("Numerical year sort failed.")
        return 0
    else:
        return 2
#before sort 6.5 (imperium) 7.9 (mr nobody) 7.3 (youth) 7.2 haynes (carol)
#order should be Mr. Nobody,youth, carol, imperium
def testNumericalRatingSort():#descending
    result = subprocess.run(["./genres", "temp.csv"],input= "7\n3\n2\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)

    outputToMatch = "Youth\nDirector: Paolo Sorrentino\nActors: Michael Caine * Harvey Keitel * Rachel Weisz * Jane Fonda\nYear: 2015 Rating: 7.3 Meta Score: 64\nDescription: A retired orchestra conductor is on holiday with his daughter and his film director best friend in the Alps when he receives an invitation from Queen Elizabeth II to perform for Prince Philip's birthday.\nWould you like to select another movie(y/n)?"
    if outputToMatch not in result.stdout:
        print("Numerical rate sort failed.")
        return 0
    else:
        return 3
#before sort 68 (imperium) 63 (mr nobody) 64 (youth) 95 haynes (carol)
#order should be carol, imperium, youth, mr.nobody
# def testNumericalMetascorSort(): #descending
    # result = subprocess.run(["./genres", "temp.csv"],input= "7\n5\n4\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    # outputToMatch = "Mr. Nobody\nDirector: Jaco Van Dormael\nActors: Jared Leto * Sarah Polley * Diane Kruger * Linh Dan Pham\nYear: 2009 Rating: 7.9 Meta Score: 63\nDescription: A boy stands on a station platform as a train is about to leave. Should he go with his mother or stay with his father? Infinite possibilities arise from this decision. As long as he doesn't choose anything is possible.\nWould you like to select another movie(y/n)?"
    # if outputToMatch not in result.stdout:
    #     print("Numerical metascore sort failed.")
    #     return 0
    # else:
    #     return 2

def testExits():
    successCount = 3
    result = subprocess.run(["./genres", "temp.csv"],input= "9\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Program does not exit at main screen")
        successCount -= 1
    result = subprocess.run(["./genres", "temp.csv"],input= "7\n4\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Program does not exit at sort screen")
        successCount -= 1
    result = subprocess.run(["./genres", "temp.csv"],input= "7\n3\n5\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Program does not exit at movie selection screen")
        successCount -= 1
    return successCount

def checkGenres():
    result = subprocess.run(["./genres", "temp.csv"],input= "1\n1\n2\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    constructedGenres = 14
    outputToMatch = "Maze Runner"
    if outputToMatch not in result.stdout:
        print("Sci-Fi genre not constructed correctly.")
        constructedGenres -=2
    result = subprocess.run(["./genres", "temp.csv"],input= "2\n1\n2\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    outputToMatch = "Mr. Nobody"
    if outputToMatch not in result.stdout:
        print("Fantasy genre not constructed correctly.")
        constructedGenres -=2
    result = subprocess.run(["./genres", "temp.csv"],input= "3\n1\n1\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Biography genre not constructed correctly.")
        constructedGenres -=2
    result = subprocess.run(["./genres", "temp.csv"],input= "4\n1\n3\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    outputToMatch1 = "Carol"
    outputToMatch2 = "Mr. Nobody"
    if outputToMatch1 not in result.stdout or outputToMatch2 not in result.stdout:
        print("Romance genre not constructed correctly.")
        constructedGenres -=2
    result = subprocess.run(["./genres", "temp.csv"],input= "5\n1\n2\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    outputToMatch = "Youth"
    if outputToMatch not in result.stdout:
        print("Comedy genre not constructed correctly.")
        constructedGenres -=2

    result = subprocess.run(["./genres", "temp.csv"],input= "6\n1\n1\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Horror genre not constructed correctly.")
        constructedGenres -=2
    result = subprocess.run(["./genres", "temp.csv"],input= "8\n1\n1\n", encoding = "utf-8",capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print("Family genre not constructed correctly.")
        constructedGenres -=2
    return constructedGenres
    

def checkMakeAndRun():
    makeResult = subprocess.call(['make'], stdout=subprocess.DEVNULL)

    #result = subprocess.run(["./genres", "temp.csv"],input= "2\n1\n1\nn\n", encoding = "utf-8",capture_output=True, text=True, timeout=1)
    t1 = testAlphabeticalSortOnTitle()
    # t2 = testAlphabeticalSortOnDirectorLast()
    t3 = testNumericalYearSort()
    t4 = testNumericalRatingSort()
    # t5 = testNumericalMetascorSort()
    t6 = testExits()
    t7 = checkGenres()
    cleanResult = subprocess.call(['make', 'clean'], stdout=subprocess.DEVNULL)

    if cleanResult != 0 :
        print("Clean command missing from makefile")
    print("End to end test score: " + str((t1+t3+t4+t6+t7)*2) + "/50")




def constructCSV():
    f = open("temp.csv", "w")
    f.write("Rank,Title,Genre,Description,Director,Actors,Year,Runtime (Minutes),Rating,Votes,Revenue (Millions),Metascore\n")
    f.write("503,Imperium,\"Crime,Drama,Thriller\",A young FBI agent eager to prove himself in the field goes undercover as a white supremacist.,Daniel Ragussis,\"Daniel Radcliffe, Toni Collette, Tracy Letts, Sam Trammell\",2016,109,6.5,27428,0,68\n")
    f.write("505,Mr. Nobody,\"Drama,Fantasy,Romance\",A boy stands on a station platform as a train is about to leave. Should he go with his mother or stay with his father? Infinite possibilities arise from this decision. As long as he doesn't choose anything is possible.,Jaco Van Dormael,\"Jared Leto,Sarah Polley,Diane Kruger,Linh Dan Pham\",2009,141,7.9,166872,0,63\n")
    f.write("501,Maze Runner: The Scorch Trials,\"Action,Sci-Fi,Thriller\",After having escaped the Maze the Gladers now face a new set of challenges on the open roads of a desolate landscape filled with unimaginable obstacles.,Wes Ball,\"Dylan O'Brien,Kaya Scodelario,Thomas Brodie-Sangster,Giancarlo Esposito\",2015,131,6.3,159364,81.69,43\n")
    f.write("504,Youth,\"Comedy,Drama,Music\",A retired orchestra conductor is on holiday with his daughter and his film director best friend in the Alps when he receives an invitation from Queen Elizabeth II to perform for Prince Philip's birthday.,Paolo Sorrentino,\"Michael Caine,Harvey Keitel,Rachel Weisz,Jane Fonda\",2015,124,7.3,52636,2.7,64\n")
    f.write("502,Carol,\"Drama,Romance\",An aspiring photographer develops an intimate relationship with an older woman in 1950s New York.,Todd Haynes,\"Cate Blanchett,Rooney Mara,Sarah Paulson,Kyle Chandler\",2015,118,7.2,77995,0.25,95")
    f.close()

constructCSV()
checkMakeAndRun()
os.remove("temp.csv")