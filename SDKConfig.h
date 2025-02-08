// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

struct SDKConfig
{
	/** The product id for the running application, found on the dev portal */
	static constexpr char ProductId[] = "57daf26c195c4cb48bc0ce54ef328efa";

	/** The sandbox id for the running application, found on the dev portal */
	static constexpr char SandboxId[] = "ec2a53a8e2154bfebc757ea5f3a7b9aa";

	/** The deployment id for the running application, found on the dev portal */
	static constexpr char DeploymentId[] = "77b058a397314d45b35f5521e88baa51";

	/** Client id of the service permissions entry, found on the dev portal */
	static constexpr char ClientCredentialsId[] = "xyza7891P2F3lIejAeaURTt0SWbdAnqh";

	/** Client secret for accessing the set of permissions, found on the dev portal */
	static constexpr char ClientCredentialsSecret[] = "jutStyAUwdAJHBhwsX3R/UF2Aw/AZCdMwkcoOKMRVEY";

	/** Game name */
	static constexpr char GameName[] = "Your game name";

	/** Encryption key */
	static constexpr char EncryptionKey[] = "1111111111111111111111111111111111111111111111111111111111111111";

	/** Credential name in the DevAuthTool */
	static constexpr char CredentialName[] = "JamesRyan";

	/** Host name in the DevAuthTool */
	static constexpr char Port[] = "localhost:1111";
};
