//
// Created by 이재현 on 2021/05/29.
//

#include "Renderer.hpp"

Camera *Renderer::getCamera() {
    return nullptr;
}

void Renderer::addEntity() {

}

void Renderer::render() {

}


void Renderer::init() {

}

Renderer::Renderer() {

}


RendererBuilder &RendererBuilder::camera(Camera camera) {
    return *this;
}

RendererBuilder &RendererBuilder::gui() {
    return *this;
}

RendererBuilder::RendererBuilder() {

}

Renderer &RendererBuilder::build() {
    return <#initializer#>;
}

RendererBuilder &RendererBuilder::light(Light light) {
    return <#initializer#>;
}
