xml version='1.0' encoding='utf-8' standalone='yes'?>
<assembly>
  <assemblyIdentity
      name="Microsoft-Windows-DHCPServer-Tools-RM"
      processorArchitecture="*"
      version="0.0.0.0"
      versionScope="nonSxS"
      />

  <migration replacementSettingsVersionRange="0"
     settingsVersion="0"
     alwaysProcess="yes">
    <registerSDF name="DHCPServer-Tools"/>
    <migXml xmlns="">
      <detects>
        <detect>
          <condition>MigXmlHelper.DoesObjectExist( "File", "%windir%\system32 [dhcpsnap.dll]" )</condition>
        </detect>
      </detects>
    </migXml>
  </migration>
</assembly>
                                                                                                                                                                                                                                                                      