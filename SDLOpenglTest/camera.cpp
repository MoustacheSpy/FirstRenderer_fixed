#include "stdafx.h"
#include "camera.h"

int Camera::processMouse_FPS()
{

    SDL_Event tempEvent;
    SDL_PollEvent(&tempEvent);
    while((tempEvent.type!=SDL_MOUSEMOTION||tempEvent.type!=SDL_MOUSEWHEEL)&&SDL_PollEvent(&tempEvent));
    if(tempEvent.type==SDL_MOUSEMOTION)
    {
        SDL_SetRelativeMouseMode(SDL_TRUE);


        GLfloat xoffset = tempEvent.motion.xrel ;
        GLfloat yoffset = 1-tempEvent.motion.yrel ; // Reversed since y-coordinates range from bottom to top



        xoffset *= sensitivity;
        yoffset *= sensitivity;
        yaw   += xoffset;
        pitch += yoffset;
        if(pitch > 89.0f)
            pitch =  89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;
        glm::vec3 front;
        front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        cameraFront = glm::normalize(front);
        /* printf("%f %f %f %d %d",pitch,yaw,roll,tempEvent.motion.xrel,tempEvent.motion.yrel);
         std::cout<< " "<<xoffset<< " "<< yoffset <<"\n";*/
        //SDL_FlushEvent(SDL_MOUSEMOTION);



    }
    else if(tempEvent.type==SDL_MOUSEWHEEL)
    {
        if(tempEvent.wheel.y<0)
            fov+=1/fov;
        else  fov-=1/fov;
    }
	return 1;
};
int Camera::processKeyboard()
{
    float trueSpeed= cameraSpeed * frameTime;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if(keystate[SDL_SCANCODE_W])
    {
        cameraPos += trueSpeed * cameraFront;
    }
    if(keystate[SDL_SCANCODE_S])
    {
        cameraPos -= trueSpeed * cameraFront;
    }
    if(keystate[SDL_SCANCODE_A])
    {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * trueSpeed;
    }
    if(keystate[SDL_SCANCODE_D])
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * trueSpeed;
    }
	return 1;

};
glm::mat4 Camera::getViewMat() {
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

glm::mat4 Camera::getProjMat(int cammode) {
	if (cammode == CAM_PERSP)
		return glm::perspective(fov, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
	else if(cammode == CAM_ORTHO)return  glm::ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, 0.1f, 100.0f);

}