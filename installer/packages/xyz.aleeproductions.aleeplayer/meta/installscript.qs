function Component()
{
    // default constructor
		
}

Component.prototype.createOperations = function()
{
    component.createOperations();
	component.addOperation("CreateShortcut", "@TargetDir@/AleePlayer.exe", "@StartMenuDir@/AleePlayer.lnk");
	component.addOperation("CreateShortcut", "@TargetDir@/maintenancetool.exe", "@StartMenuDir@/MaintenanceTool.lnk");
	
	//component.addElevatedOperation("Execute", "{0,3010,1638,5100}", "@TargetDir@\\vc_redist.x64.exe", "/norestart", "/q");
}