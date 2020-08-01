default: showevents_app timertest coffeetimer drawtest

coffeetimer: coffeetimer.cpp platform_macos.cpp platform.h utility.cpp utility.h 8x16.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -lao -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp coffeetimer.cpp gl_utility.cpp utility.cpp -o coffeetimer

drawtest: drawtest.cpp platform_macos.cpp platform.h utility.cpp utility.h 8x16.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -lao -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp drawtest.cpp gl_utility.cpp utility.cpp -o drawtest

showevents_app: showevents_app.cpp platform_macos.cpp platform.h 8x16.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -lao -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp showevents_app.cpp gl_utility.cpp -o showevents_app

timertest: timertest.cpp platform_macos.cpp platform.h 8x16.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -lao -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp timertest.cpp gl_utility.cpp -o timertest

cliptest: cliptest.cpp platform_macos.cpp platform.h 8x16.h
	c++ -g -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -lao -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp cliptest.cpp gl_utility.cpp -o cliptest

