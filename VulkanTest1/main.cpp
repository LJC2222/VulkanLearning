#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

class HelloTriangleApplication {
public:
	void run() {
		initWindow(); //初始化窗口 GLFW库函数
		initVulkan();
		mianLoop();
		cleanup(); //完成资源释放的工作。
	}

private:
	GLFWwindow * window;  //窗口对象指针
	const int WIDTH = 800;
	const int HEIGHT = 600;
	void initWindow() {
		glfwInit(); // 初始化GLFW库
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //GLFW默认会创建OpenGL环境，使用该函数阻止创建。
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //关闭窗口缩放
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);//创建窗口，(宽度, 高度, 名称, monitor to open the window, only relevant to OpenGL)

	}

	void initVulkan() {

	}

	void mianLoop() {
		while (!glfwWindowShouldClose(window)) { //未发生错误且不关闭窗口
			glfwPollEvents();//
		}
	}

	void cleanup() {
		glfwDestroyWindow(window); //销毁窗口

		glfwTerminate();//终止glfw
	}
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}