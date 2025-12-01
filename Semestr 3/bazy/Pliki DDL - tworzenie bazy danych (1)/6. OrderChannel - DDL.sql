--------------------------------------------------------
--  DDL for Table ORDERCHANNEL
--------------------------------------------------------

  CREATE TABLE "ORDERCHANNEL" 
   (	"CHANNELKEY" NUMBER(1,0), 
	"CHANNELNAME" VARCHAR2(20)
   );
--------------------------------------------------------
--  DDL for Index ORDERCHANNEL_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ORDERCHANNEL_PK" ON "ORDERCHANNEL" ("CHANNELKEY");
--------------------------------------------------------
--  DDL for Index ORDERCHANNEL_NAME_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "ORDERCHANNEL_NAME_UN" ON "ORDERCHANNEL" ("CHANNELNAME");
--------------------------------------------------------
--  Constraints for Table ORDERCHANNEL
--------------------------------------------------------

  ALTER TABLE "ORDERCHANNEL" ADD CONSTRAINT "ORDERCHANNEL_NAME_UN" UNIQUE ("CHANNELNAME") ENABLE;
 
  ALTER TABLE "ORDERCHANNEL" ADD CONSTRAINT "ORDERCHANNEL_PK" PRIMARY KEY ("CHANNELKEY") ENABLE;
 
  ALTER TABLE "ORDERCHANNEL" MODIFY ("CHANNELKEY" NOT NULL ENABLE);
 
  ALTER TABLE "ORDERCHANNEL" MODIFY ("CHANNELNAME" NOT NULL ENABLE);
