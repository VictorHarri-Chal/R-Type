/*
** EPITECH PROJECT, 2022
** Inventory (COMPONENT)
** File description:
** Inventory (COMPONENT)
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Inventory component
             *
             */
            class Inventory : public IComponent {
              public:
                /**
                 * @brief Construct a new Inventory object
                 *
                 */
                Inventory();
                /**
                 * @brief Destroy Inventory object
                 *
                 */
                ~Inventory();
                /**
                 * @brief Get the Type object
                 *
                 * @return rtype::ecs::component::compoType
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Bomb Up boost
                 *
                 * @return true if the player have the boost
                 * @return false if the player don't have the boost
                 */
                bool getBombUp() const;
                /**
                 * @brief Get the Fire Up boost
                 *
                 * @return true if the player have the boost
                 * @return false if the player don't have the boost
                 */
                bool getFireUp() const;
                /**
                 * @brief Get the Speed Up boost
                 *
                 * @return true if the player have the boost
                 * @return false if the player don't have the boost
                 */
                bool getSpeedUp() const;
                /**
                 * @brief Get the Wall Pass boost
                 *
                 * @return true if the player have the boost
                 * @return false if the player don't have the boost
                 */
                bool getWallPass() const;
                /**
                 * @brief Set the Bomb Up boost
                 *
                 * @param bonus True if the player have the boost
                 */
                void setBombUp(bool bonus);
                /**
                 * @brief Set the Fire Up boost
                 *
                 * @param bonus True if the player have the boost
                 */
                void setFireUp(bool bonus);
                /**
                 * @brief Set the Speed Up boost
                 *
                 * @param bonus True if the player have the boost
                 */
                void setSpeedUp(bool bonus);
                /**
                 * @brief Set the Wall Pass boost
                 *
                 * @param bonus True if the player have the boost
                 */
                void setWallPass(bool bonus);
                /**
                 * @brief Set the Bonus Type
                 *
                 * @param type Type of the bonus
                 */
                void setBonus(rtype::ecs::component::bonusType type);

              private:
                /**
                 * @brief Boolen to define if the player have the bomb up boost
                 *
                 */
                bool _bombUp;
                /**
                 * @brief Boolen to define if the player have the fire up boost
                 *
                 */
                bool _fireUp;
                /**
                 * @brief Boolen to define if the player have the speed up boost
                 *
                 */
                bool _speedUp;
                /**
                 * @brief Boolen to define if the player have the wall pass boost
                 *
                 */
                bool _wallPass;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !INVENTORY_HPP_ */
