--------------------------------------------------------
--  DDL for Table DELIVERYMETHOD
--------------------------------------------------------

  CREATE TABLE "DELIVERYMETHOD" 
   (	"DELIVERYMETHODKEY" NUMBER(1,0), 
	"DELIVERYMETHODNAME" VARCHAR2(20)
   );
--------------------------------------------------------
--  DDL for Index DELIVERYMETHOD_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "DELIVERYMETHOD_PK" ON "DELIVERYMETHOD" ("DELIVERYMETHODKEY");

--------------------------------------------------------
--  DDL for Index DELIVERY_NAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "DELIVERY_NAME_UQ" ON "DELIVERYMETHOD" ("DELIVERYMETHODNAME");
--------------------------------------------------------

--------------------------------------------------------
--  Constraints for Table DELIVERYMETHOD
--------------------------------------------------------

  ALTER TABLE "DELIVERYMETHOD" ADD CONSTRAINT "DELIVERYMETHOD_PK" PRIMARY KEY ("DELIVERYMETHODKEY") ENABLE;

  ALTER TABLE "DELIVERYMETHOD" ADD CONSTRAINT "DELIVERY_NAME_UQ" UNIQUE ("DELIVERYMETHODNAME") ENABLE;
 
  ALTER TABLE "DELIVERYMETHOD" MODIFY ("DELIVERYMETHODKEY" NOT NULL ENABLE);
 
  ALTER TABLE "DELIVERYMETHOD" MODIFY ("DELIVERYMETHODNAME" NOT NULL ENABLE);
