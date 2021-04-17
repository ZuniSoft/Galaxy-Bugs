//
//  CodeaProjectViewController.swift
//  Galaxian
//
//  Created by Keith R. Davis on Thursday, April 15, 2021.
//  Copyright © 2019 zunisoft. All rights reserved.
//

import UIKit
import ToolKit
import RuntimeKit
import CraftKit

class CodeaProjectViewController: CodeaViewController {

    let projectUrl = Bundle.main.url(forResource: AppDelegate.codeaProjectName, withExtension: "codea")
    
    let addon = ProjectAddon()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        initializeRenderer {
            success in
            
            if !success {
                fatalError("Failed to load Codea project")
            }
        }
    }

    func initializeRenderer(completion: @escaping (Bool)->()) {
        guard let url = projectUrl else {
            completion(false)
            return
        }
        
        let project = Project(bundlePath: url.path)
        
        register(CraftAddon())
        register(addon)
        
        AssetManager.sharedInstance().allowDropboxAssetPack = false
        AssetManager.sharedInstance().project = project
        
        runtime.project = project
        runtime.start {
            DispatchQueue.main.async {
                
                self.runtime.startAnimation()
                self.setViewMode(CodeaViewModeFullscreenNoButtons, animated: false)
                
                completion(true)
            }
        }
    }
}

