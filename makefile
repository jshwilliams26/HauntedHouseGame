default:
	g++ Space.cpp Basement.cpp Hallway.cpp Kitchen.cpp LivingRoom.cpp Outside.cpp SecretBasement.cpp Player.cpp HauntedHouse.cpp Game.cpp -o HauntedHouseGame

playertest:
	g++ Player.cpp PlayerTest.cpp -o playertest

.PHONY: clean

# This will remove both the program files and the output files
clean:
	rm -rf *.o *.out HauntedHouseGame playertest