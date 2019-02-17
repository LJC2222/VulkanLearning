#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

class HelloTriangleApplication {
public:
	void run() {
		initWindow(); //��ʼ������ GLFW�⺯��
		initVulkan();
		mianLoop();
		cleanup(); //�����Դ�ͷŵĹ�����
	}

private:
	GLFWwindow * window;  //���ڶ���ָ��
	const int WIDTH = 800;
	const int HEIGHT = 600;
	void initWindow() {
		glfwInit(); // ��ʼ��GLFW��
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //GLFWĬ�ϻᴴ��OpenGL������ʹ�øú�����ֹ������
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //�رմ�������
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);//�������ڣ�(���, �߶�, ����, monitor to open the window, only relevant to OpenGL)

	}

	void initVulkan() {

	}

	void mianLoop() {
		while (!glfwWindowShouldClose(window)) { //δ���������Ҳ��رմ���
			glfwPollEvents();//
		}
	}

	void cleanup() {
		glfwDestroyWindow(window); //���ٴ���

		glfwTerminate();//��ֹglfw
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