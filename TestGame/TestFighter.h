#pragma once
#include <cppunit/extensions/HelperMacros.h>	/**< Include for CPPUNIT_TEST_SUITE_REGISTRATION */
#include "..\Game\Character.h"					/**< Include for Fighter class and other related classes */
/**
 * @brief Test class for the Fighter class.
 *
 * This class contains unit tests for various functionalities of the Fighter class.
 */
class TestFighter : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestFighter);/**< Declare test suite. */
	CPPUNIT_TEST(testSetAbilities);
	CPPUNIT_TEST(testSetModifiers);
	CPPUNIT_TEST(testSetHitPoints);
	CPPUNIT_TEST(testSetArmorClass);
	CPPUNIT_TEST(testSetAttackBonus);
	CPPUNIT_TEST(testSetDamageBonus);
	CPPUNIT_TEST(testCalculateModifier);
	CPPUNIT_TEST(testAddItemBuff);
	CPPUNIT_TEST(testRemoveItemBuff);
	CPPUNIT_TEST(testSetArmor);
	CPPUNIT_TEST(testSetShield);
	CPPUNIT_TEST(testSetWeapon);
	CPPUNIT_TEST(testSetBoots);
	CPPUNIT_TEST(testSetRing);
	CPPUNIT_TEST(testSetHelmet);
	CPPUNIT_TEST(testSetBelt);

	CPPUNIT_TEST_SUITE_END(); /**< End of test suite declaration. */

public: 
	/** @brief Sets up the test fixture. */
	void setUp(void);	
	/** @brief Tears down the test fixture. */
	void tearDown(void);	

protected:
	/** @brief Tests setting abilities for the Fighter. */
	void testSetAbilities(void);

	/** @brief Tests setting modifiers for the Fighter. */
	void testSetModifiers(void);

	/** @brief Tests setting hit points for the Fighter. */
	void testSetHitPoints(void);

	/** @brief Tests setting armor class for the Fighter. */
	void testSetArmorClass(void);

	/** @brief Tests setting attack bonus for the Fighter. */
	void testSetAttackBonus(void);

	/** @brief Tests setting damage bonus for the Fighter. */
	void testSetDamageBonus(void);

	/** @brief Tests calculation of modifiers for the Fighter. */
	void testCalculateModifier(void);

	/** @brief Tests adding item buffs for the Fighter. */
	void testAddItemBuff(void);

	/** @brief Tests removing item buffs for the Fighter. */
	void testRemoveItemBuff(void);

	/** @brief Tests setting armor for the Fighter. */
	void testSetArmor(void);

	/** @brief Tests setting shield for the Fighter. */
	void testSetShield(void);

	/** @brief Tests setting weapon for the Fighter. */
	void testSetWeapon(void);

	/** @brief Tests setting boots for the Fighter. */
	void testSetBoots(void);

	/** @brief Tests setting ring for the Fighter. */
	void testSetRing(void);

	/** @brief Tests setting helmet for the Fighter. */
	void testSetHelmet(void);

	/** @brief Tests setting belt for the Fighter. */
	void testSetBelt(void);

private:
	Fighter* myBasicFighter;	 ///< Pointer to a basic Fighter object.
	Fighter* myFighterLlv5;		///< Pointer to a level 5 Fighter object.
	Armor* anArmor_1;			///< Pointer to an Armor object.
	Armor* anArmor_2;			///< Pointer to another Armor object.
	Ring* aRing_1;				///< Pointer to a Ring object.
	Ring* aRing_2;				///< Pointer to another Ring object.
	Helmet* aHelmet_1;			///< Pointer to a Helmet object.
	Helmet* aHelmet_2;			///< Pointer to another Helmet object.
	Boots* someBoots_1;			///< Pointer to a Boots object.
	Boots* someBoots_2;			///< Pointer to another Boots object.
	Belt* aBelt_1;				///< Pointer to a Belt object.
	Belt* aBelt_2;				///< Pointer to another Belt object.
	Shield* aShield_1;			///< Pointer to a Shield object.
	Shield* aShield_2;			///< Pointer to another Shield object.
	Weapon* aWeapon_1;			///< Pointer to a Weapon object.
	Weapon* aWeapon_2;			 ///< Pointer to another Weapon object.

};
// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(TestFighter);