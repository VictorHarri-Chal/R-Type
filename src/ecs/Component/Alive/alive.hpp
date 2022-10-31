/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** alive.hpp
*/

#pragma once

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Alive component
             *
             */
            class Alive : public IComponent {
                public:
                    /**
                     * @brief Construct a new Alive object
                     *
                     */
                    Alive();
                    /**
                     * @brief Destroy the Alive object
                     *
                     */
                    ~Alive() = default;
                    /**
                     * @brief Set if the component is alive
                     * 
                     * @param isAlive Boolean to define if alive or not
                     */
                    void setAlive(bool isAlive);
                    /**
                     * @brief Get if the component is alive
                     * 
                     * @return true If alive
                     * @return false If not alive
                     */
                    bool getAlive() const;
                    /**
                     * @brief Get the Type of the component
                     * 
                     * @return rtype::ecs::component::compoType Type of the component
                     */
                    rtype::ecs::component::compoType getType() const;

                protected:
                private:
                    /**
                     * @brief Boolean to define if alive or not
                     * 
                     */
                    bool _alive;
            };
        }
    }
}
