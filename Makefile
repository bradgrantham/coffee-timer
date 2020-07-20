default: showevents_app timertest coffeetimer

coffeetimer: coffeetimer.cpp platform_macos.cpp platform.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp coffeetimer.cpp gl_utility.cpp -o coffeetimer

showevents_app: showevents_app.cpp platform_macos.cpp platform.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp showevents_app.cpp gl_utility.cpp -o showevents_app

timertest: timertest.cpp platform_macos.cpp platform.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp timertest.cpp gl_utility.cpp -o timertest

